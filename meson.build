project(
    'kernel',
    'c',
    version : '0.0.1',
    license: ['WTFPL']
)
# generate C from vala
vala_srcs = run_command(
    'find', './src', '-type', 'f', '-iname', '*.vala'
    ).stdout().strip().split('\n')

message(vala_srcs)

srcs = ['./src/boot.S']
srcs += run_command(
    'find', './src', '-type', 'f', '-iname', '*.c'
    ).stdout().strip().split('\n')

foreach src: vala_srcs
    real_src = run_command('realpath', src).stdout().strip()
    run_command('sh', '-c',
        'cd ' + meson.current_build_dir() + '; valac '+ real_src + ' --ccode ', check:true)
    srcs += [ meson.current_build_dir() / real_src.split('/')[-1].replace('.vala','.c') ]
endforeach

args = ['-nostdlib', '-no-pie', '-m32']
args += ['-I' + meson.current_source_dir() / 'include' ]
args += ['-T' + meson.current_source_dir() / 'src/link.ld' ]

foreach arg: args
    add_project_arguments(arg, language: 'c')
endforeach

executable('kernel', srcs, link_args: args)
