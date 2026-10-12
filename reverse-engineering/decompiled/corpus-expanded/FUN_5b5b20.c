/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b5b20; label: FUN_005b5b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b5b20(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  param_1[1] = param_2[4];
  param_1[4] = uVar1;
  uVar1 = param_2[2];
  param_1[2] = param_2[8];
  param_1[8] = uVar1;
  uVar1 = param_2[6];
  param_1[6] = param_2[9];
  param_1[9] = uVar1;
  *param_1 = *param_2;
  param_1[5] = param_2[5];
  param_1[10] = param_2[10];
  param_1[0xb] = 0;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}

