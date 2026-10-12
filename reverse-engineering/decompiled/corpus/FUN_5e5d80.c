/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e5d80; label: FUN_005e5d80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e5d80(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  byte bVar12;
  int in_ECX;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  D3DPERF_BeginEvent(0xffffffff,L"bloom/dof");
  uVar11 = *(undefined4 *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar1 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  piVar9 = *(int **)(DAT_0080bbc4 + DAT_0080bbc0 * 0x28);
  piVar2 = *(int **)(DAT_0080bbdc + DAT_0080bbd8 * 0x28);
  if (*(char *)((int)piVar1 + 9) == '\0') {
    FUN_005f8ba0(piVar1[1],(char)piVar1[2]);
    *(undefined1 *)((int)piVar1 + 9) = 1;
  }
  if ((*piVar9 != 0) && (*(char *)((int)piVar9 + 9) == '\0')) {
    FUN_005f8ba0(piVar9[1],(char)piVar9[2]);
    *(undefined1 *)((int)piVar9 + 9) = 1;
  }
  iVar3 = *piVar1;
  iVar4 = *piVar2;
  iVar8 = *piVar9;
  iVar6 = FUN_005f8a80(uVar11,0,0,0);
  iVar7 = FUN_005f8a80(uVar11,4,0,0);
  if ((((*(char *)(in_ECX + 0x89) != '\0') || (*(char *)(in_ECX + 0x88) != '\0')) &&
      (FUN_005c2940(iVar3,iVar8), *(char *)(in_ECX + 0x88) != '\0')) ||
     (*(char *)(in_ECX + 0x8a) != '\0')) {
    FUN_005c2af0(iVar4);
  }
  if ((*(char *)(in_ECX + 0x89) == '\0') || (*(int *)(*(int *)(in_ECX + 0x68) + 0x28) == 0)) {
    bVar12 = 0;
  }
  else {
    bVar12 = 1;
  }
  if ((*(char *)(in_ECX + 0x89) == '\0') || (*(int *)(*(int *)(in_ECX + 0x68) + 0x28) != 0)) {
    bVar5 = 0;
  }
  else {
    bVar5 = 2;
  }
  switch(-(*(char *)(in_ECX + 0x88) != '\0') & 4U | bVar5 | bVar12) {
  case 1:
    break;
  case 2:
    break;
  default:
    FUN_005c12e0();
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
  }
  FUN_005c2760();
  if (*(char *)(in_ECX + 0x88) != '\0') {
    FUN_005f7c40(iVar3);
    FUN_005f7c50(iVar3);
    local_50 = *(undefined4 *)(in_ECX + 0x7c);
    local_4c = _DAT_0080c074;
    local_48 = 0;
    local_44 = 0;
    iVar8 = _rand();
    local_40 = (float)iVar8 / 32767.0;
    iVar8 = _rand();
    local_3c = (float)iVar8 / 32767.0;
    local_38 = 0;
    local_34 = 0;
    FUN_006e5750(0x80,&local_50,1);
    FUN_006e5750(0x81,&local_40,1);
    FUN_005f7d00(*(undefined4 *)(in_ECX + 0x54),2,2,2);
    FUN_005f7ed0(*(undefined4 *)(in_ECX + 0x54),2,2);
    FUN_005f7cc0(*(undefined4 *)(in_ECX + 0x54),0,0xd);
    iVar8 = *(int *)(in_ECX + 0x54);
    if ((iVar8 != 0) &&
       ((piVar9 = (int *)FUN_005f8460(iVar8), DAT_0097f9c0 != *piVar9 || (DAT_0097f9c4 != piVar9[1])
        ))) {
      uVar10 = FUN_005f8460(iVar8);
      FUN_005fa540(1,uVar10);
    }
    FUN_005f8550(iVar8,1);
  }
  if (*(char *)(in_ECX + 0x89) != '\0') {
    local_3c = *(float *)(*(int *)(in_ECX + 0x68) + 0x20);
    local_40 = *(float *)(*(int *)(in_ECX + 0x68) + 0x14) * *(float *)(in_ECX + 0x60);
    local_38 = 0;
    local_34 = 0;
    FUN_006e5750(0x82,&local_40,1);
    iVar8 = *(int *)(in_ECX + 0x68);
    local_2c = (*(float *)(iVar8 + 0x10) - *(float *)(iVar8 + 8)) * *(float *)(iVar8 + 0x14);
    local_28 = *(float *)(iVar8 + 4) / 180.0;
    local_24 = 180.0 / (*(float *)(iVar8 + 0xc) - *(float *)(iVar8 + 4));
    local_30 = *(float *)(iVar8 + 8) * *(float *)(iVar8 + 0x14);
    FUN_006e5750(0x88,&local_30,1);
    iVar8 = *(int *)(in_ECX + 0x68);
    if (*(int *)(iVar8 + 0x28) != 0) {
      local_1c = (*(float *)(iVar8 + 0x3c) - *(float *)(iVar8 + 0x44)) * *(float *)(iVar8 + 0x14);
      local_18 = (*(float *)(iVar8 + 0x38) * 3.1415927) / 180.0;
      local_14 = 180.0 / ((*(float *)(iVar8 + 0x40) - *(float *)(iVar8 + 0x38)) * 3.1415927);
      local_20 = *(float *)(iVar8 + 0x44) * *(float *)(iVar8 + 0x14);
      FUN_006e5750(0x89,&local_20,1);
      iVar8 = *(int *)(in_ECX + 0x68);
      local_4c = *(undefined4 *)(iVar8 + 0x30);
      local_48 = *(undefined4 *)(iVar8 + 0x34);
      local_50 = *(undefined4 *)(iVar8 + 0x2c);
      local_44 = 0x3f800000;
      FUN_005b3b30(&local_50,&local_50);
      local_44 = *(undefined4 *)(*(int *)(in_ECX + 0x68) + 0x48);
      FUN_006e5750(0x8a,&local_50,1);
    }
    FUN_005f7d00(*(undefined4 *)(in_ECX + 0x5c),2,2,0);
    FUN_005f7ed0(*(undefined4 *)(in_ECX + 0x5c),2,2);
    iVar8 = *(int *)(in_ECX + 0x5c);
    if ((iVar8 != 0) &&
       ((piVar9 = (int *)FUN_005f8460(iVar8), DAT_0097f9d0 != *piVar9 || (DAT_0097f9d4 != piVar9[1])
        ))) {
      uVar10 = FUN_005f8460(iVar8);
      FUN_005fa540(3,uVar10);
    }
    FUN_005f8550(iVar8,3);
  }
  FUN_005f7d00(iVar3,2,2,2);
  FUN_005f7ed0(iVar3,2,2);
  FUN_005f7cc0(iVar3,0,0xd);
  if ((iVar3 != 0) &&
     ((piVar9 = (int *)FUN_005f8460(iVar3), DAT_0097f9b8 != *piVar9 || (DAT_0097f9bc != piVar9[1])))
     ) {
    uVar10 = FUN_005f8460(iVar3);
    FUN_005fa540(0,uVar10);
  }
  FUN_005f8550(iVar3,0);
  if (iVar7 == 0) {
    FUN_006e5340(0x16,1);
    FUN_006e5340(0xf,0);
    FUN_006e5340(0x1b,0);
    FUN_006e5340(7,0);
    FUN_006e5340(0xa8,0xf);
  }
  else {
    FUN_005f7d00(iVar4,2,2,0);
    if ((iVar4 != 0) &&
       ((piVar9 = (int *)FUN_005f8460(iVar4), DAT_0097f9c8 != *piVar9 || (DAT_0097f9cc != piVar9[1])
        ))) {
      uVar10 = FUN_005f8460(iVar4);
      FUN_005fa540(2,uVar10);
    }
    FUN_005f8550(iVar4,2);
    FUN_006e5340(0x16,1);
    FUN_006e5340(0xf,0);
    FUN_006e5340(0x1b,0);
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,1);
    FUN_006e5340(0x17,8);
  }
  FUN_005f8bf0(uVar11);
  uVar11 = FUN_005f7c50(iVar6);
  uVar11 = FUN_005f7c40(iVar6,uVar11);
  FUN_005fa2f0(0,0,uVar11);
  FUN_005fb560();
  *piVar1 = iVar6;
  piVar1[1] = 0;
  *(undefined1 *)(piVar1 + 2) = 1;
  *(undefined1 *)((int)piVar1 + 9) = 0;
  *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = piVar1;
  if (iVar7 != 0) {
    *piVar2 = iVar7;
    piVar2[1] = 4;
    *(undefined1 *)(piVar2 + 2) = 1;
    *(undefined1 *)((int)piVar2 + 9) = 0;
    *(int **)(DAT_0080bbdc + DAT_0080bbd8 * 0x28) = piVar2;
  }
  D3DPERF_EndEvent();
  return;
}

