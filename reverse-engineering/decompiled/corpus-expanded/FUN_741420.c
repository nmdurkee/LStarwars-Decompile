/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x741420; label: FUN_00741420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00741420(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x79188) != param_1) &&
     (*(int *)(in_ECX + 0x79188) = param_1, param_1 != 0)) {
    FUN_006e5700(*(undefined4 *)(param_1 + 0x4cc));
    FUN_006e5290(*(undefined4 *)(param_1 + 0x4d0));
  }
  return;
}

