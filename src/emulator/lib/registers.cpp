#include "registers.hpp"

reg::reg(uint32_t value){
    // 32bit int
    // hex value
    m_value = value;
}

bool reg::step(){
    return true;
}

uint32_t reg::getRegister() const{
    return m_value;
}

void reg::setRegister(uint32_t value){
    m_value = value;
}

regs::regs(){
    // 32bit int
    // hex value
    m_registers[32];
}

bool regs::step(){
    for (int i = 0; i < 32; i++) m_registers[i].step();
    return true;
}

uint32_t regs::getRegisters(int index) const{
    return m_registers[index].getRegister();
}

void regs::setRegisters(int index, uint32_t value){
    m_registers[index].setRegister(value);
}