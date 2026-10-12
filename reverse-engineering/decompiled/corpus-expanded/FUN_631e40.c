/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631e40; label: FUN_00631e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00631e40(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined4 *)(param_1 + 0x2c) = param_2;
    *(undefined4 *)(param_1 + 0x30) = param_2;
  }
  return;
}

