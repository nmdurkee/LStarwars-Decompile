/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610290; label: FUN_00610290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610290(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_0060e390(param_1,param_2);
  (**(code **)(*param_1 + 4))();
  if (param_1 != *(int **)(in_ECX + 0x84)) {
    if (param_1[1] == 0) {
      *(int *)(in_ECX + 0x98) = param_1[2];
    }
    else {
      *(int *)(param_1[1] + 8) = param_1[2];
    }
    if (param_1[2] == 0) {
      *(int *)(in_ECX + 0x94) = param_1[1];
    }
    else {
      *(int *)(param_1[2] + 4) = param_1[1];
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *(int *)(in_ECX + 0x9c) = *(int *)(in_ECX + 0x9c) + -1;
    (**(code **)*param_1)(1);
  }
  return;
}

