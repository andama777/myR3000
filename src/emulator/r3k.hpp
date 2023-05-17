// r3k.cppのヘッダーファイル
#pragma once

#include <cstdint>


const int ROM_SIZE = 1024 * 1024; // 32bit * 64word

class R3K {
public:
    R3K();
    void loadProgram(char* buffer, int length);
    bool step();
    uint32_t getRegister(int index) const;
    void setRegister(int index, uint32_t value);
    uint32_t getPC() const;

private:
    uint32_t m_registers[32];
    uint32_t m_memory[ROM_SIZE];
    uint32_t m_pc;
};

