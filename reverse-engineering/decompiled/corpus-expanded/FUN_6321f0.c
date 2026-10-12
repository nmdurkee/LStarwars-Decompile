/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x6321f0; label: FUN_006321f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006321f0(int param_1)

{
  if (param_1 != 0) {
    (**(code **)(**(int **)(param_1 + 4) + 0xa8))(*(int **)(param_1 + 4));
    (**(code **)(**(int **)(param_1 + 4) + 0x44))(*(int **)(param_1 + 4),0,0,0,0);
  }
  return;
}

