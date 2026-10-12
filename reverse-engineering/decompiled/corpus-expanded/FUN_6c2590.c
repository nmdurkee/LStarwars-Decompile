/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2590; label: FUN_006c2590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2590(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_ECX + 0x14);
  if (*(int *)(in_ECX + 0x14) != 0) {
    *(int *)(*(int *)(in_ECX + 0x14) + 4) = param_1;
  }
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
  *(int *)(in_ECX + 0x14) = param_1;
  if (*(int *)(in_ECX + 0x10) == 0) {
    *(int *)(in_ECX + 0x10) = param_1;
  }
  return;
}

