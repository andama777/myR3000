// mips 32 registers
#pragma once
#include <cstdint>
#include <string>

class reg {
public:
    reg(){};
    reg(int num);
    // std::string setRegisterName(int num);
    void step();
    uint32_t getRegisterValue() const { return m_value;}
    void setRegisterValue(uint32_t value) { m_value = value;}
    std::string getRegisterName(int num) {return m_name;}
private:
    uint32_t m_value;
    std::string m_name;
};