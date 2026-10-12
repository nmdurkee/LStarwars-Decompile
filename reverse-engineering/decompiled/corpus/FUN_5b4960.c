/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b4960; label: FUN_005b4960
 */

void FUN_005b4960(float *param_1,float *param_2)

{
  param_1[0xc] = param_1[8] * param_2[2] + *param_1 * *param_2 + param_1[4] * param_2[1] +
                 param_1[0xc];
  param_1[0xd] = param_1[9] * param_2[2] + param_1[5] * param_2[1] + param_1[1] * *param_2 +
                 param_1[0xd];
  param_1[0xe] = param_1[10] * param_2[2] + param_1[6] * param_2[1] + param_1[2] * *param_2 +
                 param_1[0xe];
  return;
}

