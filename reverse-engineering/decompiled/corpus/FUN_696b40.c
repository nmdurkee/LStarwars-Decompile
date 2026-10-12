/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x696b40; label: FUN_00696b40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00696b40(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + _DAT_00810dc0 & (0 < param_2 + _DAT_00810dc0) - 1;
  if ((int)uVar1 < -10000) {
    uVar1 = 0xffffd8f0;
  }
  (**(code **)(*param_1 + 0x3c))(param_1,uVar1);
  return;
}

