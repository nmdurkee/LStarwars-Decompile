/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60e900; label: FUN_0060e900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e900(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2130) != 0) {
    FUN_0060e8b0();
    if (*(int *)(in_ECX + 0x2140) != 0) {
      if ((**(int **)(param_1 + 8) != 0) && ((*(byte *)(**(int **)(param_1 + 8) + 0x78) & 4) != 0))
      {
        *(int *)(in_ECX + 0x2140) = *(int *)(in_ECX + 0x2140) + 1;
      }
      if ((*(int *)(*(int *)(param_1 + 8) + 4) != 0) &&
         ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x78) & 4) != 0)) {
        *(int *)(in_ECX + 0x2140) = *(int *)(in_ECX + 0x2140) + 1;
      }
      if ((**(int **)(param_1 + 8) != 0) && ((*(byte *)(**(int **)(param_1 + 8) + 0x78) & 8) != 0))
      {
        *(int *)(in_ECX + 0x2140) = *(int *)(in_ECX + 0x2140) + -1;
      }
      if ((*(int *)(*(int *)(param_1 + 8) + 4) != 0) &&
         ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x78) & 8) != 0)) {
        *(int *)(in_ECX + 0x2140) = *(int *)(in_ECX + 0x2140) + -1;
      }
      if (*(int *)(in_ECX + 0x2140) < 1) {
        *(undefined4 *)(in_ECX + 0x2140) = 1;
      }
    }
  }
  return;
}

