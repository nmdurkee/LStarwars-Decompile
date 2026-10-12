/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61e5e0; label: FUN_0061e5e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061e5e0(undefined4 *param_1)

{
  float fVar1;
  undefined4 *in_ECX;
  
  if ((*(byte *)(in_ECX + 0x13) & 2) != 0) {
    fVar1 = _DAT_0080f550 - (float)(int)in_ECX[7];
    in_ECX[0x15] = fVar1;
    if (fVar1 < 5.0) {
      in_ECX[0x15] = 0x40a00000;
    }
    for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
        param_1 = (undefined4 *)*param_1) {
      if ((param_1[2] == 0x11) && (param_1 != in_ECX)) {
        param_1[0x15] = in_ECX[0x15];
      }
    }
    if (((byte)DAT_02912ec4 & 0x40) == 0) {
      in_ECX[0x13] = in_ECX[0x13] & 0xfffffffd;
    }
  }
  return 0;
}

