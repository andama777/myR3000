// mips 32 registers
#pragma once

#include <cstdint>

class reg{
public:
    reg(uint32_t value);
    bool step();
    uint32_t getRegister() const;
    void setRegister(uint32_t value);

private:
    uint32_t m_value;
};

class regs{
public:
    regs();
    bool step();
    uint32_t getRegisters(int index) const;
    void setRegisters(int index, uint32_t value);

private:
    reg m_registers[32];
};