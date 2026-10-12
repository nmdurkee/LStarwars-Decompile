/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56bf30; label: FUN_0056bf30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056bf30(int param_1)

{
  *(float *)(param_1 + 0xf18) =
       (((float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1] * _DAT_008030e8 +
        *(float *)(param_1 + 0x748)) - *(float *)(param_1 + 400)) * 10.0;
  *(float *)(param_1 + 0xf20) =
       (((float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff] *
         _DAT_008030e8 + *(float *)(param_1 + 0x750)) - *(float *)(param_1 + 0x198)) * 10.0;
  *(float *)(param_1 + 0xf1c) = (*(float *)(param_1 + 0x74c) - *(float *)(param_1 + 0x194)) * 10.0;
  return 1;
}

