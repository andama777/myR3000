#pragma once
#include <cstdint>
#include <string>
#include "register.hpp"

enum class OP_TYPE:int{
    R_TYPE,
    I_TYPE,
    J_TYPE,
    EOP_TYPE, // end of program
    ERROR_TYPE
};

enum OP : int{
    ADD, ADDU, ADDI, ADDIU,
    SUB, SUBU,
    MULT, MULTU,
    DIV, DIVU,
    AND, ANDI,
    OR, ORI,
    //XOR, XORI, NOR, NORI
    LW, SW, LUI,
    SLL, SRL,
    SLT, SLTU, SLTI, SLTIU,
    BEQ, BNE,
    J, JR, JAL,
    MFC0, MFHI, MFLO,
    UNKNOWN
};

class Instruction{
    public:
    Instruction(uint32_t instruction);
    void decode();
    void printInfo();
    private:
    std::string m_name;
    OP_TYPE m_type;
    OP m_op;
    uint32_t m_instruction;
    uint32_t m_opcode;
    uint32_t m_rs;
    uint32_t m_rt;
    uint32_t m_rd;
    uint32_t m_shamt;
    uint32_t m_funct;
    uint32_t m_addr;
    uint32_t m_imm;
};