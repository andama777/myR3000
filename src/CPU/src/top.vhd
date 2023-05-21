-- mips32 r3000 top.vhd
library ieee;
use ieee.std_logic_1164.all;

-- ISR
-- Decoder
-- Controller
-- ALU


entity top is
    port (
        CLK_50 : in std_logic;
        RST_N : in std_logic;
        Inst : in std_logic_vector(31 downto 0);
        -- mips32 r3000
        -- 32bit address bus
        -- 32bit data bus
        -- 32bit instruction bus
        -- 32bit register bus
        -- 32bit immediate bus
        -- 32bit sign extend
        -- 32bit ALU
        -- 32bit ALU result bus
        -- 32bit ALU control bus
        -- 32bit ALU control
        -- 32bit ALU control result bus
        Abus : out std_logic_vector(31 downto 0);
        Bbus : out std_logic_vector(31 downto 0);
        Sbus : out std_logic_vector(31 downto 0);
        ISR : out std_logic_vector(31 downto 0);
        Decoder : out std_logic_vector(31 downto 0);
        Reg0, Reg1, Reg2, Reg3, Reg4, Reg5, Reg6, Reg7, Reg8, Reg9, 
        Reg10, Reg11, Reg12, Reg13, Reg14, Reg15, Reg16, Reg17, Reg18, Reg19,
        Reg20, Reg21, Reg22, Reg23, Reg24, Reg25, Reg26, Reg27, Reg28, Reg29, Reg30, Reg31 : out std_logic_vector(31 downto 0)
    );
end top;

architecture rtl of top is
    signal oDecoder : std_logic_vector(31 downto 0);

    begin
    -- decoder : entity work.decoder port map (
    --     iCLK => CLK50,
    --     iRST_N => RST_N,
    --     iInst => Inst
    --     oDecoder => Decoder
    -- );

    -- regs : entity work.registers port map(
    --     CLK => CLK50,
    --     RST_N => RST_N,
    --     oReg0 => Reg0, oReg1 => Reg1, oReg2 => Reg2, oReg3 => Reg3, oReg4 => Reg4, oReg5 => Reg5, oReg6 => Reg6, oReg7 => Reg7, oReg8 => Reg8, oReg9 => Reg9,
    --     oReg10 => Reg10, oReg11 => Reg11, oReg12 => Reg12, oReg13 => Reg13, oReg14 => Reg14, oReg15 => Reg15, oReg16 => Reg16, oReg17 => Reg17, oReg18 => Reg18, oReg19 => Reg19,
    --     oReg20 => Reg20, oReg21 => Reg21, oReg22 => Reg22, oReg23 => Reg23, oReg24 => Reg24, oReg25 => Reg25, oReg26 => Reg26, oReg27 => Reg27, oReg28 => Reg28, oReg29 => Reg29, oReg30 => Reg30, oReg31 => Reg31
    -- );

    -- alu : entity work.alu port map(
    --     iCtr => oDecoder,
    --     iAbus => Abus,
    --     iBbus => Bbus,
    --     oSbus => Sbus
    -- );

    






    
    

end rtl;
