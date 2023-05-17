rm rom*
mips-linux-gnu-gcc -O0 -S -mips32 main.c -o rom.s
mips-linux-gnu-as -mips32 rom.s -o rom.o
mips-linux-gnu-ld rom.o -o rom.bin
cp rom.bin ../emulator/rom/rom.bin