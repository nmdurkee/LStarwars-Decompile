/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46dc10; label: FUN_0046dc10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046dc10(int param_1,float *param_2,int param_3)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 == 0) {
    return;
  }
  if (param_2 == (float *)0x0) {
    return;
  }
  if (param_3 != 0) {
    if (*(char *)(param_1 + 0x61) == '\0') {
      local_c = -0.04;
      local_8 = *(float *)(param_1 + 0x74);
      local_4 = -0.3;
      goto LAB_0046dc8e;
    }
    if (*(char *)(param_1 + 0x61) == '\x01') {
      local_c = 0.035;
      local_8 = *(float *)(param_1 + 0x74);
      local_4 = -0.25;
      goto LAB_0046dc8e;
    }
  }
  local_4 = *(float *)(param_1 + 0x78);
  local_8 = *(float *)(param_1 + 0x74);
  local_c = *(float *)(param_1 + 0x70);
LAB_0046dc8e:
  FUN_005b3620(&local_c,&local_c,*(undefined2 *)(param_1 + 0x5c));
  fVar1 = *(float *)(param_1 + 0x58);
  *param_2 = *(float *)(param_1 + 0x50) + local_c;
  param_2[1] = local_8;
  param_2[2] = fVar1 + local_4;
  return;
}

