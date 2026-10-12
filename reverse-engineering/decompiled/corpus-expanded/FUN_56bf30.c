/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56bf30; label: FUN_0056bf30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

