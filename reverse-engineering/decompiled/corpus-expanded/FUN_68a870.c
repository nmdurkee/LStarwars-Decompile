/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68a870; label: FUN_0068a870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068a870(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  if (DAT_02921884 != -1) {
    *(undefined4 *)(DAT_02921884 * 0x50 + 0x38 + DAT_02962a14) = *(undefined4 *)(param_2 + 0x54);
    iVar2 = DAT_029629c4;
    if (*(float *)(DAT_02921884 * 0x50 + 0x3c + DAT_02962a14) < *(float *)(param_2 + 0x54)) {
      *(undefined4 *)(DAT_02921884 * 0x50 + 0x3c + DAT_02962a14) = *(undefined4 *)(param_2 + 0x54);
      fVar1 = *(float *)(param_2 + 0x54);
      *(float *)(iVar2 + 0x54) = fVar1;
      *(float *)(iVar2 + 0x50) = (fVar1 - *(float *)(iVar2 + 0x58)) / *(float *)(iVar2 + 0x5c);
    }
  }
  FUN_00689f70();
  return;
}

