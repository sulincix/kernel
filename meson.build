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

srcs = ['./src/boot.s']
srcs += run_command(
    'find', './src', '-type', 'f', '-iname', '*.c'
    ).stdout().strip().split('\n')
srcs += run_command(
    'find', './src', '-type', 'f', '-iname', '*.s'
    ).stdout().strip().split('\n')



real_vala_srcs = []
foreach src: vala_srcs
    real_vala_srcs += run_command('realpath', src).stdout().strip()
    srcs += [ meson.current_build_dir() / src.split('/')[-1].replace('.vala','.c') ]
endforeach

run_command('sh', '-c',
        'cd ' + meson.current_build_dir() + '; valac '+ ' '.join(real_vala_srcs) + ' --ccode ', check:true)

args = ['-nostdlib', '-no-pie', '-m32', '-O3']
args += ['-I' + meson.current_source_dir() / 'include' ]
args += ['-T' + meson.current_source_dir() / 'src/link.ld' ]

foreach arg: args
    add_project_arguments(arg, language: 'c')
endforeach

executable('kernel', srcs, link_args: args)
