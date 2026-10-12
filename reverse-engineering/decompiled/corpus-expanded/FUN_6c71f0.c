/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c71f0; label: FUN_006c71f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c71f0(undefined4 *param_1)

{
  int in_ECX;
  
  DAT_02973e91 = 1;
  if (param_1[9] != 0) {
    if (param_1[0xb] == 0) {
      *(undefined4 *)(in_ECX + 0x9c) = param_1[0xc];
    }
    else {
      *(undefined4 *)(param_1[0xb] + 0x30) = param_1[0xc];
    }
    if (param_1[0xc] == 0) {
      *(undefined4 *)(in_ECX + 0x98) = param_1[0xb];
    }
    else {
      *(undefined4 *)(param_1[0xc] + 0x2c) = param_1[0xb];
    }
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    *(int *)(in_ECX + 0xa0) = *(int *)(in_ECX + 0xa0) + -1;
    (**(code **)*param_1)(1);
  }
  return;
}

