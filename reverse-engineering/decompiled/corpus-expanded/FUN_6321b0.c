/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x6321b0; label: FUN_006321b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006321b0(int param_1)

{
  if (param_1 != 0) {
    (**(code **)(**(int **)(param_1 + 4) + 0xac))
              (*(int **)(param_1 + 4),0,0,1,0xff000000,0x3f800000,0);
    (**(code **)(**(int **)(param_1 + 4) + 0xa4))(*(int **)(param_1 + 4));
  }
  return;
}

