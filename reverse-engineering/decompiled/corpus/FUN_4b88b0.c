/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b88b0; label: FUN_004b88b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b88b0(float param_1,float param_2,float param_3,float param_4,int param_5,float param_6,
                 int param_7)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  bool bVar4;
  int in_EAX;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  float10 fVar10;
  float *pfVar11;
  float local_80;
  float local_7c;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [64];
  
  if (((DAT_0093b2a8 == 0) || (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b160)) ||
     (*(char *)(in_EAX + 0x107e) != '\n')) {
    if ((*(uint *)(in_EAX + 0xeec) & 0x8000000) == 0) {
      cVar9 = false;
    }
    else {
      cVar9 = DAT_0087b9b4 != 0;
      DAT_0087b9b4 = 0;
    }
  }
  else {
    cVar9 = true;
  }
  local_50 = ((*(int *)(in_EAX + 0xcd0) != 0) + 0xcc) * 0x10;
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + local_50) == '\0') {
    return;
  }
  bVar1 = *(byte *)(in_EAX + 0x107e);
  if (bVar1 == 0) {
    uVar5 = 1;
    uVar8 = 1;
  }
  else {
    uVar8 = (uint)*(char *)(in_EAX + 0x107f);
    uVar5 = (uint)bVar1;
    if (((DAT_007f17a4 != 0) && ((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0)) ||
       (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f4)) {
      if (((bVar1 & 1) == 0) || (uVar5 != uVar8)) {
        uVar7 = uVar8 & 1;
      }
      else {
        uVar7 = 0;
      }
      uVar8 = (int)uVar8 / 2 + uVar7;
      uVar5 = uVar5 / 2;
      if ((bVar1 & 1) != 0) {
        uVar5 = uVar5 + 1;
      }
    }
  }
  bVar4 = false;
  if (((bool)cVar9 != false) && (uVar5 < 2)) {
    cVar9 = false;
  }
  if (((((*(char *)(in_EAX + 0x280) == '\0') || (*(char *)(in_EAX + 0x280) == '\x01')) &&
       (1 < uVar5)) && ((*(char *)(in_EAX + 0x28b) != '\0' && (0.0 < *(float *)(in_EAX + 0x1010)))))
     && (*(float *)(in_EAX + 0x1010) < 1.0)) {
    bVar4 = true;
    uVar8 = FUN_006e6b90();
  }
  local_7c = _DAT_007fc308 * param_3;
  iVar6 = FUN_00574e20();
  cVar2 = DAT_00876577;
  if (iVar6 != 4) {
    if (DAT_0093b0d8 == 0) goto LAB_004b8a5c;
    cVar2 = *(char *)(DAT_0093b0d8 + 0xb);
  }
  if (cVar2 != '\0') {
    local_7c = _DAT_007fc394 * local_7c;
  }
LAB_004b8a5c:
  if (param_5 == 0) {
    if ((bool)cVar9 == false) {
      param_1 = param_1 - (float)(int)(uVar5 - 1) * local_7c * 0.5;
    }
    else {
      param_1 = param_1 - (float)(int)(uVar5 / 2 - 1) * local_7c * 0.5;
    }
  }
  else if (param_5 == 8) {
    local_7c = -local_7c;
  }
  iVar6 = 0;
  local_5c = _DAT_0087b998 * param_2;
  local_44 = param_3;
  local_64 = param_3;
  local_54 = param_1;
  if (uVar5 == 0) {
    return;
  }
  do {
    if ((cVar9 == '\x01') && ((int)(uVar5 / 2) <= iVar6)) {
      cVar9 = '\x02';
      local_5c = local_5c - _DAT_007fc30c * param_3;
      param_1 = local_54;
    }
    local_58 = 0x3f8020c5;
    local_68 = param_3;
    local_6c = param_3;
    if (iVar6 < (int)uVar8) {
      local_80 = 1.0;
      if ((((param_7 != 0) && (!bVar4)) && (0 < (int)uVar8)) && (iVar6 == uVar8 - 1)) {
        if ((iVar6 == 0) && (uVar8 == 1)) {
          local_74 = 0.5;
        }
        else {
          local_74 = 0.2;
        }
        fVar10 = (float10)FUN_005b7d30(_DAT_00925028,0x3f000000);
        fVar3 = (float)((float10)local_74 - (fVar10 + fVar10) * (float10)local_74) + 1.0;
        local_6c = fVar3 * local_6c;
        local_68 = fVar3 * local_68;
        local_58 = 0x3f7fbe77;
      }
    }
    else {
      local_80 = 0.5;
    }
    if (param_4 == 1.0) {
      pfVar11 = &local_6c;
    }
    else {
      pfVar11 = &local_4c;
      local_4c = local_6c * param_4;
      local_48 = param_4 * local_68;
    }
    FUN_005b45a0(local_40,pfVar11);
    local_60 = _DAT_0087b938 * param_1;
    FUN_005b4900(local_40,&local_60);
    FUN_00552e00(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + local_50,local_40,local_80 * param_6);
    param_1 = local_7c + param_1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < (int)uVar5);
  return;
}

