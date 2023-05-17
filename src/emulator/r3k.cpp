#include "r3k.hpp"

R3K::R3K() {
    // レジスタを初期化する
    for (int i = 0; i < 32; i++) {
        m_registers[i] = 0;
    }

    // メモリを初期化する
    for (int i = 0; i < ROM_SIZE; i++) {
        m_memory[i] = 0;
    }

    // PC を初期化する
    m_pc = 0;
}

void R3K::loadProgram(char* buffer, int length) {
    // プログラムをメモリにロードする
    for (int i = 0; i < length; i += 4) {
        uint32_t instruction = (buffer[i] << 24) | (buffer[i + 1] << 16) | (buffer[i + 2] << 8) | buffer[i + 3];
        m_memory[i / 4] = instruction;
    }
}

bool R3K::step() {
    // 命令を取得する
    uint32_t instruction = m_memory[m_pc / 4];

    // 命令を解析する
    uint32_t opcode = instruction >> 26;
    uint32_t rs = (instruction >> 21) & 0x1F;
    uint32_t rt = (instruction >> 16) & 0x1F;
    uint32_t rd = (instruction >> 11) & 0x1F;
    uint32_t shamt = (instruction >> 6) & 0x1F;
    uint32_t funct = instruction & 0x3F;
    uint32_t immediate = instruction & 0xFFFF;
    uint32_t address = instruction & 0x3FFFFFF;

    // PC を更新する
    m_pc += 4;

    // 命令を実行する
    switch (opcode) {
        case 0x00: // R-type
            switch (funct) {
                case 0x20: // add
                    m_registers[rd] = m_registers[rs] + m_registers[rt];
                    break;
                case 0x22: // sub
                    m_registers[rd] = m_registers[rs] - m_registers[rt];
                    break;
                case 0x24: // and
                    m_registers[rd] = m_registers[rs] & m_registers[rt];
                    break;
                case 0x25: // or
                    m_registers[rd] = m_registers[rs] | m_registers[rt];
                    break;
                case 0x2A: // slt
                    m_registers[rd] = (m_registers[rs] < m_registers[rt]) ? 1 : 0;
                    break;
                default:
                    return false; // 不明な命令
            }
            break;
        case 0x08: // addi
            m_registers[rt] = m_registers[rs] + static_cast<int16_t>(immediate);
            break;
        case 0x0C: // andi
            m_registers[rt] = m_registers[rs] & immediate;
            break;
        case 0x0D: // ori
            m_registers[rt] = m_registers[rs] | immediate;
            break;
        case 0x23: // lw
            m_registers[rt] = m_memory[(m_registers[rs] + static_cast<int16_t>(immediate)) / 4];
            break;
        case 0x2B: // sw
            m_memory[(m_registers[rs] + static_cast<int16_t>(immediate)) / 4] = m_registers[rt];
            break;
        case 0x04: // beq
            if (m_registers[rs] == m_registers[rt]) {
                m_pc += static_cast<int16_t>(immediate) << 2;
            }
            break;
        case 0x02: // j
            m_pc = (m_pc & 0xF0000000) | (address << 2);
            break;
        case 0x03: // jal
            m_registers[31] = m_pc;
            m_pc = (m_pc & 0xF0000000) | (address << 2);
            break;
        default:
            return false; // 不明な命令
    }

    return true;
}

uint32_t R3K::getRegister(int index) const {
    return m_registers[index];
}

void R3K::setRegister(int index, uint32_t value) {
    m_registers[index] = value;
}

uint32_t R3K::getPC() const {
    return m_pc;
}
