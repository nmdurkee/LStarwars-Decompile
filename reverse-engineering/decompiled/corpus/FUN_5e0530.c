/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e0530; label: FUN_005e0530
 */

void FUN_005e0530(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  char *in_ECX;
  
  if (*in_ECX == -0x71) {
    FUN_005e0490();
    return;
  }
  if (param_5 == 0) {
    if ((((*(uint *)(param_1 + 0xb4) & 0x80000000) != 0) && (1 < param_2)) &&
       ((cVar1 = in_ECX[-0x20], cVar1 == -0x50 || ((cVar1 == -0x52 || (cVar1 == -0x51)))))) {
      FUN_005e02b0();
      return;
    }
    FUN_005e0200();
    return;
  }
  FUN_005e0390();
  return;
}

