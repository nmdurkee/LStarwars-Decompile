/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x415770; label: FUN_00415770
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415770(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  bool bVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  bool bVar11;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  fVar1 = *(float *)(param_1 + 0xda8);
  bVar4 = false;
  *(undefined4 *)(param_1 + 0xda8) = 0;
  if (DAT_0087b738 != 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0xef4) & 0x10000000) != 0) {
    return;
  }
  piVar9 = &DAT_0093d7f4;
  do {
    iVar6 = piVar9[-1];
    if ((((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) && (*(int *)(iVar6 + 0x798) != 0)) &&
       (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == param_1)) {
      bVar4 = true;
    }
    iVar6 = *piVar9;
    if (((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) &&
       ((*(int *)(iVar6 + 0x798) != 0 && (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == param_1)))) {
      bVar4 = true;
    }
    iVar6 = piVar9[1];
    if (((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) &&
       ((*(int *)(iVar6 + 0x798) != 0 && (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == param_1)))) {
      bVar4 = true;
    }
    iVar6 = piVar9[2];
    if ((((iVar6 != 0) && (*(char *)(iVar6 + 0x7b5) == 'Q')) && (*(int *)(iVar6 + 0x798) != 0)) &&
       (*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) == param_1)) {
      bVar4 = true;
    }
    piVar9 = piVar9 + 4;
  } while ((int)piVar9 < 0x93d814);
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) && (!bVar4)) {
    return;
  }
  if (*(char *)(param_1 + 0x28b) != '\0') {
    return;
  }
  cVar3 = *(char *)(param_1 + 0x7b5);
  if (cVar3 == '+') {
    return;
  }
  if ((*(uint *)(param_1 + 0xef0) & 0x40000) == 0) {
    return;
  }
  if (cVar3 == '\x0f') {
    return;
  }
  if (cVar3 == 'G') {
    return;
  }
  if (cVar3 == '\x1f') {
    return;
  }
  if (cVar3 == 'F') {
    return;
  }
  if (cVar3 == 'Q') {
    return;
  }
  if (DAT_00855de0 != 0) {
    return;
  }
  iVar6 = FUN_00574e20();
  if (iVar6 != -1) {
    return;
  }
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0dc) && (PTR_DAT_008021b4[0x22c] == '\v')) {
    FUN_00415510();
    return;
  }
  if (DAT_00951288 == 0) {
    if ((param_1 == DAT_0093d7f0) && (DAT_0093d7f4 != 0)) {
      if ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0) {
        return;
      }
      if (*(char *)(DAT_0093d7f4 + 0x7b5) == '+') {
        return;
      }
    }
    if (param_1 != DAT_0093d7f4) goto LAB_00415953;
    if (DAT_0093d7f0 != 0) {
      if ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0) {
        return;
      }
      if (*(char *)(DAT_0093d7f0 + 0x7b5) == '+') {
        return;
      }
      goto LAB_00415953;
    }
LAB_00415974:
    bVar4 = false;
  }
  else {
LAB_00415953:
    if ((((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) ||
        (DAT_0093d7f4 == 0)) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) goto LAB_00415974;
    bVar4 = true;
  }
  if (DAT_00951288 == 0) {
    fVar2 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
  }
  else {
    fVar2 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x18);
  }
  local_c = *(float *)(param_1 + 0x68);
  local_8 = *(undefined4 *)(param_1 + 0x6c);
  local_4 = *(float *)(param_1 + 0x70);
  iVar6 = param_1 + 0x68;
  iVar10 = param_1 + 0x80;
  iVar7 = FUN_0054fd90(iVar10,&DAT_009250d0,&DAT_009250dc,0,0,0);
  bVar11 = iVar7 != 0;
  if (bVar11) {
    FUN_00572810(&DAT_009250dc,&local_c,&local_c,0);
    local_c = local_c + fVar2 * _DAT_009250dc;
    local_4 = fVar2 * _DAT_009250e4 + local_4;
  }
  iVar7 = FUN_0054fd90(iVar10,&DAT_00925100,&DAT_0092510c,0,-*(float *)(param_1 + 0x1dc),0);
  if (iVar7 == 0) {
    iVar7 = FUN_0054fd90(iVar10,&DAT_009250e8,&DAT_009250f4,0,-*(float *)(param_1 + 0x1dc),0);
    if (iVar7 != 0) {
      FUN_00572810(&DAT_009250f4,iVar6,&local_c,0);
      local_c = local_c + fVar2 * _DAT_009250f4;
      fVar5 = _DAT_009250fc;
      goto LAB_00415acf;
    }
  }
  else {
    FUN_00572810(&DAT_0092510c,iVar6,&local_c);
    local_c = local_c + fVar2 * _DAT_0092510c;
    fVar5 = _DAT_00925114;
LAB_00415acf:
    local_4 = fVar2 * fVar5 + local_4;
    bVar11 = true;
  }
  if ((((DAT_00951288 != 0) &&
       ((*(int *)(PTR_DAT_00802c54 + 300) == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)
        ))) || (DAT_00855de4 == 0)) ||
     ((bVar4 && (uVar8 = FUN_00550040(0,*(undefined2 *)(PTR_DAT_008021b4 + 0x1f8)),
                0x2000 < (int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)))))) {
    iVar7 = FUN_0054fd90(iVar10,&DAT_00925130,&DAT_0092513c,0,-*(float *)(param_1 + 0x1e0),0);
    if (iVar7 == 0) {
      iVar7 = FUN_0054fd90(iVar10,&DAT_00925118,&DAT_00925124,0,-*(float *)(param_1 + 0x1e0),0);
      if (iVar7 == 0) goto LAB_00415c09;
      if (*(float *)(PTR_DAT_008021b4 + 0x114) <= 0.0) goto LAB_00415b79;
LAB_00415bbc:
      iVar7 = 0;
    }
    else {
      if (*(float *)(PTR_DAT_008021b4 + 0x114) <= 0.0) goto LAB_00415bbc;
LAB_00415b79:
      iVar7 = 5;
    }
    FUN_00572810(&DAT_009250dc + iVar7 * 0x18,iVar6,&local_c,0);
    local_c = local_c + fVar2 * *(float *)(&DAT_009250dc + iVar7 * 0x18);
    local_4 = fVar2 * *(float *)(&DAT_009250e4 + iVar7 * 0x18) + local_4;
  }
  else {
LAB_00415c09:
    if (!bVar11) {
      *(undefined4 *)(param_1 + 0xda8) = 0;
      return;
    }
  }
  *(float *)(param_1 + 0x200) = local_c;
  *(float *)(param_1 + 0x208) = local_4;
  *(float *)(param_1 + 0xda8) = _DAT_00925018 + fVar1;
  FUN_0058b180(param_1);
  return;
}

