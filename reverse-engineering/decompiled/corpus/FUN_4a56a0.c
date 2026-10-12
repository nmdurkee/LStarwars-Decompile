/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a56a0; label: FUN_004a56a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a56a0(int param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  short local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = *(int *)(param_1 + 0xd8);
  if ((*(byte *)(param_1 + 0x144) & 0x80) == 0) {
    if (iVar5 != 0) {
      iVar6 = param_1 + 0x30;
      FUN_005b3800(&local_24,iVar5 + 0x80,iVar6);
      fVar2 = local_24 * local_24 + local_1c * local_1c;
      iVar8 = FUN_005be2d0(local_24,local_1c);
      FUN_005b3620(&local_24,&local_24,-iVar8);
      local_20 = (*(float *)(iVar5 + 0x84) + 0.5) - *(float *)(param_1 + 0x34);
      iVar9 = FUN_005be2d0(local_20,local_1c);
      uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x138),-iVar9,0x3f800000);
      *(undefined2 *)(param_1 + 0x138) = uVar4;
      uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x13a),iVar8,0x40800000);
      fVar3 = _DAT_007fc224;
      *(undefined2 *)(param_1 + 0x13a) = uVar4;
      if (fVar2 < fVar3 * fVar3) {
        *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 0x80;
        FUN_005b3800(&local_24,iVar5 + 0x80,iVar6);
        FUN_005b3830(&local_24,&local_24,0x40a00000);
        FUN_005b37d0(param_1 + 0xbc,iVar6,&local_24);
        *(undefined4 *)(param_1 + 0xd8) = 0;
        fVar10 = (float10)FUN_005c0240(local_20 * local_20 + fVar2);
        *(float *)(param_1 + 0x100) = (float)fVar10 / _DAT_007fc078;
      }
    }
    *(undefined4 *)(param_1 + 0x130) = 60000;
  }
  else {
    FUN_005b3800(&local_24,param_1 + 0xbc,param_1 + 0x30);
    iVar5 = FUN_005be2d0(local_24,local_1c);
    FUN_005b3620(&local_24,&local_24,-iVar5);
    iVar6 = FUN_005be2d0(local_20,local_1c);
    uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x138),-iVar6,0x41000000);
    *(undefined2 *)(param_1 + 0x138) = uVar4;
    uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x13a),iVar5,0x41000000);
    *(undefined2 *)(param_1 + 0x13a) = uVar4;
    FUN_0054fb40((float)*(int *)(param_1 + 0x130),0,0x3f800000);
    uVar7 = FUN_006e6b90();
    *(undefined4 *)(param_1 + 0x130) = uVar7;
  }
  pfVar1 = (float *)(param_1 + 0x80);
  local_28 = (short)(int)ROUND((float)*(int *)(param_1 + 0x130) * _DAT_00925018);
  *(short *)(param_1 + 0x13c) = *(short *)(param_1 + 0x13c) + local_28;
  *pfVar1 = 0.0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(float *)(param_1 + 0x88) = _DAT_007fc078;
  FUN_005b35a0(pfVar1,pfVar1,*(undefined2 *)(param_1 + 0x138));
  FUN_005b3620(pfVar1,pfVar1,*(undefined2 *)(param_1 + 0x13a));
  local_c = *(float *)(param_1 + 0x30) + param_2 * *pfVar1;
  local_8 = *(float *)(param_1 + 0xe8) * param_2 +
            *(float *)(param_1 + 0x84) * param_2 + *(float *)(param_1 + 0x34);
  local_4 = param_2 * *(float *)(param_1 + 0x88) + *(float *)(param_1 + 0x38);
  uVar7 = FUN_005be590(*(undefined2 *)(param_1 + 0x138),0x4000);
  FUN_005b45f0(param_1,uVar7);
  FUN_005b4f70(param_1,*(undefined2 *)(param_1 + 0x13a));
  FUN_005b5060(param_1,*(undefined2 *)(param_1 + 0x13c));
  FUN_005b4900(param_1,&local_c);
  if (*(float *)(param_1 + 0xfc) < 0.2) {
    local_18 = *(float *)(param_1 + 0xfc) / 0.2;
    local_14 = local_18;
    local_10 = local_18;
    FUN_005b4c30(param_1,&local_18);
  }
  if ((*(byte *)(param_1 + 0x144) & 0x80) != 0) {
    uVar7 = FUN_0062c300(0x3f800000,_DAT_00925018);
    local_24 = -*pfVar1;
    local_20 = -*(float *)(param_1 + 0x84);
    local_1c = -*(float *)(param_1 + 0x88);
    FUN_0062c760(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0xb,&local_c,uVar7,&local_24);
  }
  return;
}

