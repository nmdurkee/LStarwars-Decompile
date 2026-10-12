/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b35a0; label: FUN_005b35a0
 */

void FUN_005b35a0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)(&DAT_029899a0)[param_3 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_3 >> 1 & 0x7fff];
  fVar3 = (float)param_2[1];
  *param_1 = *param_2;
  param_1[1] = fVar1 * fVar3 - fVar2 * (float)param_2[2];
  param_1[2] = fVar3 * fVar2 + fVar1 * (float)param_2[2];
  return;
}

