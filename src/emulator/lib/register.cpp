#include "register.hpp"

reg::reg(int num){
    m_value = 0x00000000;
    std::string name;
    if (num == 0) name = "zero";
    else if(num == 1) name = "at";
    else if(num == 2) name = "v0";
    else if(num == 3) name = "v1";
    else if(4 <= num && num <= 7) name = "a" + std::to_string(num - 4);
    else if(8 <= num && num <= 15) name = "t" + std::to_string(num - 8);
    else if(16 <= num && num <= 23) name = "s" + std::to_string(num - 16);
    else if(num == 24) name = "t8";
    else if(num == 25) name = "t9";
    else if(num == 26) name = "k0";
    else if(num == 27) name = "k1";
    else if(num == 28) name = "gp";
    else if(num == 29) name = "sp";
    else if(num == 30) name = "fp";
    else if(num == 31) name = "ra";
    else if(num == 32) name = "Hi";
    else if(num == 33) name = "Lo";
    else name = "error";
    m_name = name;
}

void reg::step(){
    // do nothing

}

