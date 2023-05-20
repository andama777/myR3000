// r3k.cppのヘッダーファイル
#pragma once
#include <stdio.h>
#include <cstdint>
// std::cout を使いたい
#include <iostream>
// std::bitset を使いたい
#include <bitset>
#include <string>

#include "register.hpp"
#include "instruction.hpp"

const int WORD_SIZE = 4;
const int BIT_WIDTH = 32; // 32bit
const int ROM_WIDTH = 1024; // 2**30 だけど、メモリが足りないので 2**10 にする
const int ROM_SIZE = WORD_SIZE * ROM_WIDTH; //2**30 memory words

class R3K {
public:
    R3K();
    void loadProgram(const char* buffer, int length);
    void run();
    void step();

private:
    reg m_registers[35];
    uint32_t m_memory[ROM_SIZE];
    uint32_t m_pc;
};