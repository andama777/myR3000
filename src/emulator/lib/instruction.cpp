#include "instruction.hpp"

Instruction::Instruction(uint32_t instruction) {
    m_instruction = instruction;
    m_opcode = instruction >> 26;
    m_rs = (instruction >> 21) & 0x1F;
    m_rt = (instruction >> 16) & 0x1F;
    m_rd = (instruction >> 11) & 0x1F;
    m_shamt = (instruction >> 6) & 0x1F;
    m_funct = instruction & 0x3F;
    m_addr = instruction & 0x3FFFFFF;
    m_imm = instruction & 0xFFFF;
}

void Instruction::printInfo(){
    std::string rs, rt, rd;
    //printf("operation = %s\n", m_name.c_str());
    if (m_type == OP_TYPE::R_TYPE){
        rs = reg(m_rs).getRegisterName(m_rs);
        rt = reg(m_rt).getRegisterName(m_rt);
        rd = reg(m_rd).getRegisterName(m_rd);
        printf("%s %s %s %s\n", m_name.c_str(), rd.c_str(), rs.c_str(), rt.c_str());
        printf("shamt = %d\n", m_shamt);
        printf("funct = %d\n", m_funct);
    }else if (m_type == OP_TYPE::I_TYPE){
        rs = reg(m_rs).getRegisterName(m_rs);
        rt = reg(m_rt).getRegisterName(m_rt);
        printf("%s %s %s %d\n", m_name.c_str(), rt.c_str(), rs.c_str(), m_imm);
    }else if (m_type == OP_TYPE::J_TYPE){
        printf("addr = %04x\n", m_addr);
    }else {
        printf("error\n");
    }
    
}

void Instruction::decode(){
    // m_opcodeとm_functから命令タイプを判定し、printInfo(OP op)に渡す
    switch(m_opcode){
        case 0x00:
            // R型
            m_type = OP_TYPE::R_TYPE;
            switch(m_funct){
                case 0x00:
                    m_op = OP::SLL;
                    m_name = "SLL";
                    break;
                case 0x02:
                    m_op = OP::SRL;
                    m_name = "SRL";
                    break;
                
                case 0x08: // JR
                    m_op = OP::JR;
                    m_name = "JR";
                    break;
                // MF
                case 0x10:
                    m_op = OP::MFHI;
                    m_name = "MFHI";
                    break;
                case 0x12:
                    m_op = OP::MFLO;
                    m_name = "MFLO";
                    break;

                // MUL DIV
                case 0x18:
                    m_op = OP::MULT;
                    m_name = "MULT";
                    break;
                case 0x19:
                    m_op = OP::MULTU;
                    m_name = "MULTU";
                    break;
                case 0x1A:
                    m_op = OP::DIV;
                    m_name = "DIV";
                    break;
                case 0x1B:
                    m_op = OP::DIVU;
                    m_name = "DIVU";
                    break;

                // ADD SUB AND OR SLT
                case 0x20:
                    m_op = OP::ADD;
                    m_name = "ADD";
                    break;
                case 0x21:
                    m_op = OP::ADDU;
                    m_name = "ADDU";
                    break;
                case 0x22:
                    m_op = OP::SUB;
                    m_name = "SUB";
                    break;
                case 0x23:
                    m_op = OP::SUBU;
                    m_name = "SUBU";
                    break;
                case 0x24:
                    m_op = OP::AND;
                    m_name = "AND";
                    break;
                case 0x25:
                    m_op = OP::OR;
                    m_name = "OR";
                    break;

                // SLT
                case 0x2A:
                    m_op = OP::SLT;
                    m_name = "SLT";
                    break;
                case 0x2B:
                    m_op = OP::SLTU;
                    m_name = "SLTU";
                    break;
                
                default:
                    m_type = OP_TYPE::ERROR_TYPE;
                    m_op = OP::UNKNOWN;
                    m_name = "UNKNOWN";
                    break;
            }
            break;

        // J型
        case 0x02:
            m_type = OP_TYPE::J_TYPE;
            m_op = OP::J;
            m_name = "J";
            break;
        case 0x03:
            m_type = OP_TYPE::J_TYPE;
            m_op = OP::JAL;
            m_name = "JAL";
            break;

        // I型
        case 0x04:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::BEQ;
            m_name = "BEQ";
            break;
        case 0x05:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::BNE;
            m_name = "BNE";
            break;
        case 0x08:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::ADDI;
            m_name = "ADDI";
            break;
        case 0x09:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::ADDIU;
            m_name = "ADDIU";
            break;
        case 0x0A:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::SLTI;
            m_name = "SLTI";
            break;
        case 0x0B:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::SLTIU;
            m_name = "SLTIU";
            break;
        case 0x0C:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::ANDI;
            m_name = "ANDI";
            break;
        case 0x0D:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::ORI;
            m_name = "ORI";
            break;
        case 0x0F:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::LUI;
            m_name = "LUI";
            break;
        case 0x13:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::LW;
            m_name = "LW";
            break;
        case 0x1B:
            m_type = OP_TYPE::I_TYPE;
            m_op = OP::SW;
            m_name = "SW";
            break;
        default:
            m_type = OP_TYPE::ERROR_TYPE;
            m_op = OP::UNKNOWN;
            m_name = "UNKNOWN";
            break;
    }
}

