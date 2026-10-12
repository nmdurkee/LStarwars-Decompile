/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d2c40; label: FUN_004d2c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d2c40(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  char local_75;
  uint local_74;
  uint local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c;
  undefined1 local_58 [4];
  float local_54;
  uint local_4c;
  uint local_48;
  undefined1 local_40 [64];
  
  local_68 = FUN_005806a0(0xf,PTR_DAT_00802c54);
  if (((param_1 == 0) || (param_2 == 0)) || ((*(byte *)(param_2 + 1) & 8) != 0)) {
    return;
  }
  iVar2 = *(int *)(param_2 + 0x84);
  local_6c = (*(float *)(param_1 + 0xd0) - *(float *)(param_1 + 200)) * *(float *)(param_1 + 0xcc);
  if (iVar2 == 0) {
    local_6c = local_6c * local_6c;
    iVar2 = FUN_004d29f0(PTR_DAT_00802c54,param_1 + 0x88,local_6c,&local_75);
  }
  else {
    local_75 = *(char *)(param_2 + 4);
  }
  if (iVar2 == 0) {
    if (*(float *)(param_1 + 200) != 0.0) {
      return;
    }
    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) + 6.0;
    return;
  }
  if (local_75 == '\0') {
    iVar3 = iVar2 + 0x4c;
  }
  else if (local_75 == '\x01') {
    iVar3 = FUN_005cf9e0(*(int *)(iVar2 + 0x1c) + 4);
  }
  else {
    if (local_75 != '\x02') goto LAB_004d2d27;
    iVar3 = iVar2 + 0x28;
  }
  if (iVar3 != 0) {
    FUN_005b3800(local_58,iVar3,param_1 + 0x88);
  }
LAB_004d2d27:
  local_6c = local_54 + 0.1;
  local_54 = 0.0;
  fVar4 = (float10)FUN_005bec80(local_58);
  local_5c = (float)(fVar4 / (float10)*(float *)(param_1 + 0xcc) + (float10)0.05000000074505806);
  if (*(float *)(param_1 + 200) == 0.0) {
    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) + 6.0;
    *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 4;
    *(int *)(param_2 + 0x84) = iVar2;
    return;
  }
  if ((*(byte *)(param_2 + 1) & 0x10) == 0) {
    puVar1 = (undefined4 *)(param_1 + 0xa0);
    FUN_0054ff40(puVar1,&local_64,&local_60);
    *puVar1 = 0;
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xcc);
    local_54 = local_6c;
    FUN_005b3b30(local_58,local_58);
    FUN_0054ff40(local_58,&local_74,&local_70);
    iVar3 = FUN_006e6b90();
    local_6c = ((float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + 1.0) * 15.0;
    local_74 = FUN_00550070(local_64,local_74,local_6c);
    local_74 = local_74 & 0xffff;
    local_70 = FUN_00550070(local_60,local_70,local_6c);
    local_70 = local_70 & 0xffff;
    FUN_005b44e0(local_40);
    local_4c = local_74 & 0xffff;
    local_48 = local_70 & 0xffff;
    FUN_005c0820(local_40,&local_4c);
    FUN_005b3200(puVar1,puVar1,local_40);
    FUN_005b3b30(param_1 + 0xac,puVar1);
    local_5c = *(float *)(param_1 + 200) + local_5c;
    if ((*(float *)(param_1 + 0xd0) < local_5c) && ((*(byte *)(param_2 + 1) & 8) == 0)) {
      *(float *)(param_1 + 0xd0) = local_5c;
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 4;
      *(int *)(param_2 + 0x84) = iVar2;
      return;
    }
  }
  *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 4;
  *(int *)(param_2 + 0x84) = iVar2;
  return;
}

