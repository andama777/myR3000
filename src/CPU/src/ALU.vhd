-- mips32 ALU zero_flag

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU is
    port (
        a, b : in std_logic_vector(31 downto 0);
        op   : in std_logic_vector(3 downto 0);
        q    : out std_logic_vector(31 downto 0);
        zero_flag    : out std_logic
    );
end entity ALU;

architecture rtl of ALU is
    signal q_s : std_logic_vector(31 downto 0);
    signal zero_s : std_logic;
begin
    process (a, b, op) begin
        case op is
            when "0000" =>
                q_S <= a and b;
            when "0001" =>
                q_s <= a or b;
            when "0010" =>
                q_s <= std_logic_vector(unsigned(a) + unsigned(b));
            when "0110" =>
                q_s <= std_logic_vector(signed(a) - signed(b));
            when "1100" =>
                q_s <= not (a or b);
            when others =>
                q_s <= (others => 'X');
        end case;

        -- q_s is a std_logic_vector, so it can't be compared to 0
        -- directly.  We need to convert it to unsigned first.
        -- if unsigned(q_s) = 0 then
        --     zero_s <= '1';
        -- if q_s = "00000000000000000000000000000000" then
        --     zero_s <= '1';
        -- if q_s = (others => '0') then
        --     zero_s <= '1';

        if unsigned(q_s) = 0 then
            zero_s <= '1';
        else
            zero_s <= '0';
        end if;

        q <= q_s;
        zero_flag <= zero_s;
    end process;
end architecture;