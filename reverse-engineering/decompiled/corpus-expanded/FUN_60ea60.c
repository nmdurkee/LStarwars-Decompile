/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60ea60; label: FUN_0060ea60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ea60(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -1;
    FUN_004ef660(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 4),param_1,1);
  }
  return;
}

