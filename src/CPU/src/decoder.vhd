-- mips32 r3000 decoder

library ieee;
use ieee.std_logic_1164.all;

entity decoder is
    port (
        iInst : in std_logic_vector(31 downto 0);
        -- i_opcode : in std_logic_vector(5 downto 0);
        -- i_funct  : in std_logic_vector(5 downto 0);
        -- i_memrd  : in std_logic;
        -- i_memwr  : in std_logic;
        -- i_regwr  : in std_logic;
        -- i_branch : in std_logic;
        -- i_jump   : in std_logic;
        -- i_memop  : in std_logic_vector(1 downto 0);
        -- i_aluop  : in std_logic_vector(2 downto 0);
        -- i_regdst : in std_logic;
        -- i_pcsrc  : in std_logic;

        o_aluop  : out std_logic_vector(2 downto 0);
        -- o_memop  : out std_logic_vector(1 downto 0);
        -- o_regdst : out std_logic;
        -- o_regwr  : out std_logic;
        -- o_memwr  : out std_logic;
        -- o_memrd  : out std_logic;
        -- o_pcsrc  : out std_logic;
        -- o_branch : out std_logic;
        -- o_jump   : out std_logic
    );
end decoder;

architecture rtl of decoder is
    signal s_aluop  : std_logic_vector(2 downto 0);
    signal s_memop  : std_logic_vector(1 downto 0);
    signal s_regdst : std_logic;
    signal s_regwr  : std_logic;
    signal s_memwr  : std_logic;
    signal s_memrd  : std_logic;
    signal s_pcsrc  : std_logic;
    signal s_branch : std_logic;
    signal s_jump   : std_logic;

    begin
    process (i_opcode) begin
        s_aluop <= "000";
        s_memop <= "00";
        s_regdst <= '0';
        s_regwr <= '0';
        s_memwr <= '0';
        s_memrd <= '0';
        s_pcsrc <= '0';
        s_branch <= '0';
        s_jump <= '0';
    end process;