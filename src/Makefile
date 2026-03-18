all:
	mkdir -p build
	clang --target=aarch64 -ffreestanding -nostdlib -c src/kernel.c -o build/kernel.o
	clang --target=aarch64 -ffreestanding -c src/boot.s -o build/boot.o
	ld.lld build/boot.o build/kernel.o -o build/kernel.bin -Ttext=0x200000 --entry=_start --image-base=0x200000

run: all
	qemu-system-aarch64 -M virt -cpu cortex-a57 -nographic -kernel build/kernel.bin
