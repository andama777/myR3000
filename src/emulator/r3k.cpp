#include "r3k.hpp"

R3K::R3K() {
    std::string name;
    for (int i = 0; i < 34; i++) m_registers[i] = reg(i);
    printf("success: initialized registers\n");

    for (int i = 0; i < ROM_SIZE; i++) m_memory[i] = 0x00000000;
    printf("success: initialized memory\n");

    m_pc = 0x00000000;
}

void R3K::loadProgram(const char* buffer, int length) {
    // プログラムをメモリにロードする
    // for (int i = 0; i < length; i += 4) {
    //     m_memory[i / 4] = (buffer[i] << 24) | (buffer[i + 1] << 16) | (buffer[i + 2] << 8) | buffer[i + 3];
    // }
    m_memory[0] = 0x014B4820;
}

void R3K::run(){
    while (true) {
        if (m_memory[m_pc / 4] == 0x00000000) {
            printf("Program Counter: %d\n", m_pc);
            printf("No operation \n");
            printf("Program finished\n");
            break;
        }
        step();
    }
}

void R3K::step() {
    // 命令を取得する
    Instruction inst = m_memory[m_registers[31].getRegisterValue() / 4];
    inst.decode();
    printf("------------------------\n");
    printf("Program Counter: %d\n", m_pc);
    inst.printInfo();
    printf("------------------------\n");

    // 命令を実行する
    
    // プログラムカウンタを更新する
    m_pc += 4;
}