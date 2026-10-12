/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x415c60; label: FUN_00415c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415c60(int param_1)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  int local_24;
  uint local_20;
  float local_1c;
  undefined1 local_18 [4];
  float local_14;
  undefined1 local_c [12];
  
  *(undefined4 *)(param_1 + 0x218) = *(undefined4 *)(param_1 + 0x21c);
  iVar6 = *(int *)(param_1 + 0xca4);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x5c);
  iVar5 = param_1 + 0x5c;
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
  *(undefined1 *)(param_1 + 0x282) = *(undefined1 *)(param_1 + 0x281);
  *(undefined4 *)(iVar6 + 0x38) = *(undefined4 *)(iVar6 + 0x28);
  *(undefined2 *)(iVar6 + 0x58) = *(undefined2 *)(iVar6 + 0x26);
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xffffbfff;
  *(undefined2 *)(param_1 + 0x1060) = *(undefined2 *)(param_1 + 0x27a);
  if (*(char *)(param_1 + 0x288) == '\0') {
    fVar2 = *(float *)(param_1 + 0xf10) + _DAT_00925018;
  }
  else {
    fVar2 = 0.0;
  }
  *(float *)(param_1 + 0xf10) = fVar2;
  if (*(char *)(param_1 + 0x7b5) == '+') {
    *(float *)(param_1 + 0xd98) = *(float *)(param_1 + 0xd98) + _DAT_00925018;
  }
  if (*(float *)(param_1 + 0xed4) == 1e+09) {
    fVar2 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
  }
  else {
    fVar2 = *(float *)(param_1 + 0xed4);
  }
  local_1c = _DAT_00925018 * fVar2;
  FUN_005518a0((undefined4 *)(param_1 + 0xe64),local_1c);
  FUN_00550a20(*(undefined4 *)(param_1 + 0xe64),*(undefined4 *)(param_1 + 0xe80),local_18,&local_24,
               &local_20,(int)*(char *)(param_1 + 0xe6a));
  if (local_1c < 0.0) {
    local_24 = local_24 + 0x8000;
    local_20 = -local_20 & 0xffff;
  }
  *(short *)(param_1 + 0x5a) = (short)local_24;
  uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x58),local_24,_DAT_007f2388);
  *(undefined2 *)(param_1 + 0x58) = uVar4;
  *(undefined2 *)(param_1 + 0x27a) = uVar4;
  uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x278),-local_20,_DAT_007f2388);
  *(undefined2 *)(param_1 + 0x278) = uVar4;
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0a0) || (0.0 < fVar2)) {
    fVar7 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0xe90),-*(float *)(param_1 + 0xe84),
                                  _DAT_007f238c);
    *(float *)(param_1 + 0xe90) = (float)fVar7;
  }
  pfVar1 = (float *)(param_1 + 0xe84);
  fVar2 = *(float *)(param_1 + 0xe90) * _DAT_00925018 + *pfVar1;
  *pfVar1 = fVar2;
  if (((fVar2 != 0.0) || (*(float *)(param_1 + 0xe88) != 0.0)) ||
     (*(float *)(param_1 + 0xe8c) != 0.0)) {
    FUN_005b35a0(local_c,pfVar1,*(undefined2 *)(param_1 + 0x278));
    FUN_005b3620(local_c,local_c,*(undefined2 *)(param_1 + 0x27a));
    FUN_005b37d0(local_18,local_18,local_c);
  }
  if ((*(uint *)(param_1 + 0xef4) & 0x1000) == 0) goto LAB_00416005;
  fVar7 = (float10)FUN_00498590(param_1,0);
  fVar2 = (*(float *)(param_1 + 0x84) - *(float *)(param_1 + 0x1a0)) + (float)fVar7;
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) {
    FUN_0067a6d0();
  }
  fVar7 = (float10)FUN_005506f0(param_1,local_18,0x40a00000,0x1f);
  local_1c = (float)fVar7;
  *(float *)(param_1 + 0x21c) = local_1c;
  if (local_1c == 2e+06) {
    fVar7 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x60),fVar2,0x40a00000);
LAB_00415fdf:
    local_14 = (float)fVar7;
  }
  else {
    fVar7 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x60),local_1c + fVar2,0x40a00000);
    local_14 = (float)fVar7;
    if (local_14 < *(float *)(param_1 + 0x21c)) {
      fVar7 = (float10)*(float *)(param_1 + 0x21c);
      goto LAB_00415fdf;
    }
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) {
    local_14 = *(float *)(param_1 + 0xe88) + local_14;
  }
LAB_00416005:
  if (((0.0 < *(float *)(param_1 + 0xd48)) && (cVar3 = *(char *)(param_1 + 0x7b5), cVar3 != '*')) &&
     ((cVar3 != '6' && (cVar3 != ':')))) {
    *(float *)(param_1 + 0xd48) = *(float *)(param_1 + 0xd48) - _DAT_00925018;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) {
    fVar7 = (float10)FUN_00498320(param_1);
    local_14 = (float)(fVar7 + (float10)local_14);
  }
  FUN_0054fb80(iVar5,iVar5,local_18,_DAT_007f2384);
  iVar6 = param_1 + 0x68;
  FUN_005b3800(iVar6,iVar5,param_1 + 0x8c);
  FUN_005b3830(iVar6,iVar6,1.0 / _DAT_00925018);
  *(undefined1 *)(param_1 + 0x107a) = 0;
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 1) != 0) {
    cVar3 = *(char *)(param_1 + 0x7b5);
    if (((cVar3 == '*') || (cVar3 == '6')) || (cVar3 == ':')) {
      iVar5 = 0;
    }
    else {
      FUN_00550040(*(undefined2 *)(param_1 + 0x1060),*(undefined2 *)(param_1 + 0x27a));
      iVar5 = FUN_006e6b90();
      iVar6 = FUN_006e6b90();
      iVar5 = iVar5 + iVar6;
      if (iVar5 < -0x10000) {
        iVar5 = -0x10000;
      }
      else if (0x10000 < iVar5) {
        iVar5 = 0x10000;
      }
    }
    iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
    if (iVar5 < -0x2000) {
      iVar5 = -0x2000;
    }
    else if (0x2000 < iVar5) {
      iVar5 = 0x2000;
    }
    uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0xe18),iVar5,0x41000000);
    *(undefined2 *)(param_1 + 0xe18) = uVar4;
  }
  FUN_0062b040(param_1);
  FUN_0055d2b0(param_1);
  return;
}

