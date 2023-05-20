// mips r3000 emulator
#include <cstdio>
#include <cstdint>

#include "r3k.hpp"

int main(){
    // build.binからの相対パス
    const char* ROM_PATH = "../rom/rom.bin";
    // ファイルを開く
    FILE* file = fopen(ROM_PATH, "rb");
    if (file == NULL) {
        printf("error: failed to open %s\n", ROM_PATH);
        return -1;
    }
    printf("success: opened %s\n", ROM_PATH);

    // ファイルサイズを取得する
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // ファイルを読み込む
    char* buffer = new char[length];
    fread(buffer, 1, length, file);
    fclose(file);
    
    // エミュレータを初期化する
    R3K r3k = R3K();
    r3k.loadProgram(buffer, length);

    // エミュレータを実行する
    r3k.run();
    //r3k.step();

    // メモリを解放する
    //delete[] buffer;

    return 0;
}