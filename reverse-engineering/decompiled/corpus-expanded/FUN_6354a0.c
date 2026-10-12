/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x6354a0; label: FUN_006354a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006354a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x43340000;
  param_1[4] = 0x3f800000;
  *param_1 = 1;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[10] = 0;
  param_1[7] = 0;
  param_1[0x2a] = 0;
  param_1[8] = 0x40800000;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[9] = 0;
  param_1[0x2d] = 1;
  param_1[0x154] = 0;
  param_1[0xb] = 0x3f13b646;
  param_1[0x155] = 0xffffffff;
  param_1[0xc] = 0x3f13b646;
  param_1[0x158] = 0;
  param_1[0xd] = 0x3f13b646;
  puVar1 = param_1 + 0x34;
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0xf] = 0x3f800000;
  param_1[0x12] = 0x3f800000;
  param_1[0x10] = 0x43340000;
  puVar3 = param_1;
  puVar4 = param_1 + 0x15;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x2e] = 0x3f800000;
  param_1[0x2f] = 0x40800000;
  param_1[0x30] = 0x3e4ccccd;
  param_1[0x31] = 0x3f000000;
  param_1[0x32] = 0x3ff33333;
  param_1[0x33] = 0;
  iVar2 = 0x20;
  param_1[0x156] = 0x3f800000;
  param_1[0x157] = 0x3e4ccccd;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

