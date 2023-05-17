`sudo apt install clang`
`sudo apt install llvm`
`sudo apt install binutils-mips-linux-gnu`
`clang -O3 -S -target mips -mcpu=mips32 main.c -o rom.s`
`mips-linux-gnu-as -mips32 rom.s -o rom.o`
`mips-linux-gnu-ld rom.o -o rom.bin`

rom.s: Assembler messages:
rom.s:43: Error: unknown pseudo-op: `.addrsig'


`clang -O3 -S -target mips -mcpu=mips32 main.c -o rom.s`
でできた

`clang -O3 -S -target mips -mcpu=mips32 main.c -I/path/to/mylib/headers -L/path/to/mylib/libs -lmylib -o main`
これをやるはず

`clang -O3 -target mips -mcpu=mips32 main.c -o rom`
その後llvm-objcopyを使って.elf -> .binに変換する
`llvm-objcopy -O binary rom.elf rom.bin`
rom.binを作るにはこれ

`clang -O3 -target mips -mcpu=mips32 main.c -o rom.elf`
llvm-objcopy -O binary rom.elf rom.bin

`clang -O0 -S -target mips -mcpu=mips32 -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -no-integrated-as main.c -o rom.s`
`mips-linux-gnu-as -mips32 rom.s -o rom.o`
`mips-linux-gnu-ld rom.o -o rom.bin`

## mips linux gnu gccでやってみる
```
sudo apt install gcc-mips-linux-gnu
rm rom*
mips-linux-gnu-gcc -O0 -S -mips32 main.c -o rom.s
mips-linux-gnu-as -mips32 rom.s -o rom.o
mips-linux-gnu-ld rom.o -o rom.bin
```
でできた warning出るけど


