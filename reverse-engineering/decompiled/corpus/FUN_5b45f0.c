/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b45f0; label: FUN_005b45f0
 */

void FUN_005b45f0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  
  uVar1 = (&DAT_029899a0)[param_2 + 0x4000 >> 1 & 0x7fff];
  param_1[10] = uVar1;
  param_1[5] = uVar1;
  fVar2 = (float)(&DAT_029899a0)[param_2 >> 1 & 0x7fff];
  param_1[6] = fVar2;
  param_1[9] = -fVar2;
  *param_1 = 0x3f800000;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[4] = 0;
  param_1[0xb] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}

