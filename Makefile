all: build

clean:
	rm -rf build || true

build: clean
	meson setup build
	ninja -C build