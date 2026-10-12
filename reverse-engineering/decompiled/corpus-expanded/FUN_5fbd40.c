/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fbd40; label: FUN_005fbd40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fbd40(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 8))(*(int **)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))(*(int **)(param_1 + 0x18));
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 8))(*(int **)(param_1 + 0x14));
  }
  return 1;
}

