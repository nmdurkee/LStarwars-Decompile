/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e09a0; label: FUN_005e09a0
 */

void FUN_005e09a0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (in_EAX != (byte *)0x0) {
    do {
      FUN_005e05e0(in_EAX,iVar1,param_2,param_3,param_4);
      if (((param_1 & 1) == 0) || (in_EAX[1] != 1)) {
        in_EAX = in_EAX + 0x10;
      }
      else {
        in_EAX = *(byte **)(in_EAX + 4);
      }
      iVar1 = iVar1 + 1;
    } while ((uint)*in_EAX != (-(uint)((param_1 & 2) != 0) & 0xfffffff6) + 0x8e);
    FUN_005e05e0(in_EAX,iVar1,param_2,param_3,param_4);
  }
  return;
}

