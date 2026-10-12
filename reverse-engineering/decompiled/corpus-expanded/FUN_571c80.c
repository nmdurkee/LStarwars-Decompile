/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x571c80; label: FUN_00571c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00571c80(float param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((0.0 < *(float *)((int)param_1 + 0x100)) && (2 < DAT_00925068 % 6)) {
    pbVar1 = (byte *)((int)param_1 + 0x20a);
    param_1 = 2.0;
    if ((*pbVar1 & 1) != 0) {
      param_1 = 1.0;
    }
    if (*(float *)(iVar2 + 0x100) < param_1) {
      return 0;
    }
  }
  return 1;
}

