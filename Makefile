build: clean
	mkdir build
	cd build ; valac ../src/*.vala --ccode
	cd build ; gcc -I../fake-glib ../src/*.c ../src/boot.S ./*.c -T ../src/link.ld -o os.bin -nostdlib -no-pie -m32
clean:
	rm -rf build
