/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ee60; label: FUN_0061ee60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061ee60(int param_1,undefined4 *param_2)

{
  param_2[1] = 0;
  *param_2 = *(undefined4 *)(param_1 + 0x80);
  if (*(int *)(param_1 + 0x80) != 0) {
    *(undefined4 **)(*(int *)(param_1 + 0x80) + 4) = param_2;
  }
  *(undefined4 **)(param_1 + 0x80) = param_2;
  return;
}

