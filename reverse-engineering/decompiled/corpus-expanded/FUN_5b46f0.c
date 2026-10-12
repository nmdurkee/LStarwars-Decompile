/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b46f0; label: FUN_005b46f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b46f0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  
  uVar1 = (&DAT_029899a0)[param_2 + 0x4000 >> 1 & 0x7fff];
  param_1[5] = uVar1;
  *param_1 = uVar1;
  fVar2 = (float)(&DAT_029899a0)[param_2 >> 1 & 0x7fff];
  param_1[1] = fVar2;
  param_1[4] = -fVar2;
  param_1[10] = 0x3f800000;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0xb] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[2] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}

