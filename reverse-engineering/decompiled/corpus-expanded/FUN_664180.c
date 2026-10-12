/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664180; label: FUN_00664180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00664180(undefined4 param_1,int param_2)

{
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(byte *)(*(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4) + 0x12) = *(byte *)(param_2 + 0x11) & 1;
  }
  return;
}

