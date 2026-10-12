/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646d20; label: FUN_00646d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646d20(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (DAT_02920970 != 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 == 0) {
      *(undefined4 *)(DAT_02920970 + 0xe0) = *(undefined4 *)(param_2 + 0x54);
      return;
    }
    if (iVar1 == 1) {
      *(undefined4 *)(DAT_02920970 + 0xe4) = *(undefined4 *)(param_2 + 0x54);
      return;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(DAT_02920970 + 0xe8) = *(undefined4 *)(param_2 + 0x54);
    }
  }
  return;
}

