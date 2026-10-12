/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ec10; label: FUN_0061ec10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061ec10(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    if (*(int *)(iVar1 + 8) == 0x13) {
      FUN_0061eb60(iVar1);
    }
  }
  return;
}

