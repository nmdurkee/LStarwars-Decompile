/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a76c0; label: FUN_004a76c0
 */

undefined4 FUN_004a76c0(int param_1,ushort param_2,float param_3)

{
  ushort uVar1;
  uint uVar2;
  float local_c [2];
  float local_4;
  
  if ((*(char *)(param_1 + 0x281) == '\0') ||
     ((ABS(*(float *)(param_1 + 0xf24)) <= 0.001 && (ABS(*(float *)(param_1 + 0xf2c)) <= 0.001)))) {
    uVar1 = *(ushort *)(param_1 + 0x5a);
  }
  else {
    uVar1 = FUN_005be2d0(*(undefined4 *)(param_1 + 0xf24),*(undefined4 *)(param_1 + 0xf2c));
  }
  uVar2 = (uint)uVar1;
  *(float *)(param_1 + 0xf18) = (float)(&DAT_029899a0)[uVar1 >> 1] * 1.2;
  *(float *)(param_1 + 0xf20) = (float)(&DAT_029899a0)[(int)(uVar2 + 0x4000) >> 1 & 0x7fff] * 1.2;
  if ((*(char *)(param_1 + 0x281) != '\0') && (0.0 < param_3)) {
    local_c[0] = (float)(&DAT_029899a0)[param_2 >> 1] * param_3;
    local_4 = param_3 * (float)(&DAT_029899a0)[(int)(param_2 + 0x4000) >> 1 & 0x7fff];
    FUN_005b3620(local_c,local_c,-uVar2);
    local_4 = 0.0;
    FUN_005b3620(local_c,local_c,uVar2);
    *(float *)(param_1 + 0xf18) = *(float *)(param_1 + 0xf18) + local_c[0];
    *(float *)(param_1 + 0xf20) = *(float *)(param_1 + 0xf20) + local_4;
    return 0;
  }
  return 0;
}

