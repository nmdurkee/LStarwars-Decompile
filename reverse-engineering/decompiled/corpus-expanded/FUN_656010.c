/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x656010; label: FUN_00656010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00656010(int param_1)

{
  if (*(int *)(param_1 + 0x1cc) == 0) {
    DAT_029620a8 = *(int *)(param_1 + 0x1c8);
    if (DAT_029620a8 != 0) {
      *(undefined4 *)(DAT_029620a8 + 0x1cc) = 0;
      *(undefined4 *)(param_1 + 0x1c8) = 0;
      *(undefined4 *)(param_1 + 0x1cc) = 0;
      return;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
    if (*(int *)(param_1 + 0x1c8) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x1cc) = *(undefined4 *)(param_1 + 0x1cc);
    }
  }
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  return;
}

