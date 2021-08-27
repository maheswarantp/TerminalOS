C_SOURCES = ${wildcard kernel/*.c kernel/*/*.c drivers/*/*.c cpu/*.c libc/*/*.c cpu/*/*.c}
HEADERS = ${wildcard kernel/*.h kernel/*/*.h drivers/*/*.h cpu/*.h libc/*/*.h cpu/*/*.h}
ASM = ${wildcard kernel/*.asm cpu/*.asm}

OBJ = ${C_SOURCES:.c=.o}
ASM_OBJ = ${ASM:.asm=.o}

GCC = i386-elf-gcc 
LD = i386-elf-ld 

all: run

bin/boot.bin: boot/boot.asm
	nasm $< -f bin -o $@

# Wildcard compilation targets
%.o: %.c ${HEADERS}
	${GCC} -ffreestanding -c $< -o $@

%.o: %.asm 
	nasm $< -f elf -o $@

print:
	echo ${OBJ}


# Linking
bin/kernel.bin:${ASM_OBJ} ${OBJ}
	# echo ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

os-image.bin: bin/boot.bin bin/kernel.bin
	cat $^ > $@

run: os-image.bin
	cp $< debug/$<
	qemu-img resize $< +20k
	qemu-system-i386 -hda $<

clean:
	rm -f */*.bin *.bin */*.o */*/*.o *.o */*.elf *.elf