/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ee90; label: FUN_0061ee90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061ee90(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x80) == param_2) {
    *(int *)(param_1 + 0x80) = *param_2;
  }
  if (*param_2 != 0) {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  return;
}

