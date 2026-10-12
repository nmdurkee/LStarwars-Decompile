/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610100; label: FUN_00610100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610100(int param_1)

{
  undefined4 *in_ECX;
  
  if (*(int *)(param_1 + 4) == 0) {
    in_ECX[1] = *(undefined4 *)(param_1 + 8);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 8);
  }
  if (*(int *)(param_1 + 8) == 0) {
    *in_ECX = *(undefined4 *)(param_1 + 4);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = *(undefined4 *)(param_1 + 4);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  in_ECX[2] = in_ECX[2] + -1;
  return;
}

