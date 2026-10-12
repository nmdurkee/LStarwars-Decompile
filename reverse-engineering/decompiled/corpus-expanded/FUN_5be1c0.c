/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be1c0; label: FUN_005be1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005be1c0(float param_1,float param_2)

{
  int iVar1;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  if (param_2 < param_1) {
    iVar1 = FUN_006e6b90();
    return (float10)((1.0 - (float)(extraout_ST0 - (float10)iVar1)) *
                     (float)(int)(0x4000 - (uint)*(ushort *)(&DAT_008066c8 + iVar1 * 2)) +
                    (float)(int)(0x4000 - (uint)*(ushort *)(&DAT_008066ca + iVar1 * 2)) *
                    (float)(extraout_ST0 - (float10)iVar1));
  }
  if (param_2 == param_1) {
    return (float10)DAT_00806ac8;
  }
  iVar1 = FUN_006e6b90();
  return (float10)((1.0 - (float)(extraout_ST0_00 - (float10)iVar1)) *
                   (float)*(ushort *)(&DAT_008066c8 + iVar1 * 2) +
                  (float)*(ushort *)(&DAT_008066ca + iVar1 * 2) *
                  (float)(extraout_ST0_00 - (float10)iVar1));
}

