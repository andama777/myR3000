# R3000 emu 自作

## instruction

### R-Type


## regs
$zero 0
$at 1 アセンブラが使用
$v0,v1 2,3 関数の返り値
$a0~a3 4~7 引数
$t0~t7 8~15 一時変数
$s0~s7 16~23 保存変数 退避が必要な変数
$t8~t9 24~25 一時変数
$k0~k1 26~27 OSが使用
$gp 28 Global Pointer
$sp 29 Stack Pointer
$fp 30 Frame Pointer
$ra 31 Return Address

## process
R-Type
1. p297
2. p298