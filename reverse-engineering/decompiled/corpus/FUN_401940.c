/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x401940; label: FUN_00401940
 */

undefined4 FUN_00401940(int param_1,int param_2,int *param_3)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  
  puVar10 = (undefined4 *)0x0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  if ((*(byte *)(param_2 + 0x210) & 1) == 0) {
    return 0;
  }
  if (7 < *(byte *)(param_2 + 0x20c)) {
    return 0;
  }
  if (param_3 == (int *)0x0) {
    return 0;
  }
  iVar6 = FUN_0055a120(param_3);
  if (iVar6 != 0) {
    puVar10 = (undefined4 *)FUN_0051ac10(param_1,iVar6);
  }
  uVar7 = (uint)*(byte *)((int)param_3 + 6);
  if (uVar7 == DAT_007faaa4) {
    iVar6 = *param_3;
    *(int **)(param_2 + 4 + (uint)*(byte *)(param_2 + 0x20c) * 4) = param_3;
    if (puVar10 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)(param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
      *puVar10 = *(undefined4 *)(iVar6 + 0x40);
      puVar10[1] = *(undefined4 *)(iVar6 + 0x44);
      puVar10[2] = *(undefined4 *)(iVar6 + 0x48);
      iVar1 = param_2 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c;
      iVar9 = iVar1 + 0x34;
      FUN_0043e040(param_1,iVar9,iVar1 + 0x44,iVar9,0,0xff);
      uVar8 = FUN_005be2d0(*(float *)(iVar6 + 0x68) - *(float *)(iVar6 + 0x40),
                           *(float *)(iVar6 + 0x70) - *(float *)(iVar6 + 0x48));
      *(undefined4 *)(param_2 + 0x40 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c) = uVar8;
    }
    else {
      puVar11 = (undefined4 *)(param_2 + 0x24 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
      for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
    }
    goto LAB_00401a64;
  }
  if (uVar7 == DAT_00802644) {
    iVar6 = *param_3;
    cVar4 = *(char *)(iVar6 + 0x91);
    if ((((cVar4 != '\x01') && (cVar4 != '\x02')) && (cVar4 != '\x05')) &&
       ((cVar4 != '\x06' && (cVar4 != '\a')))) {
      return 0;
    }
    *(int **)(param_2 + 4 + (uint)*(byte *)(param_2 + 0x20c) * 4) = param_3;
    if (puVar10 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)(param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
      *puVar10 = *(undefined4 *)(iVar6 + 0x1c);
      puVar10[1] = *(undefined4 *)(iVar6 + 0x20);
      puVar10[2] = *(undefined4 *)(iVar6 + 0x24);
      bVar5 = *(byte *)(param_2 + 0x20c);
LAB_00401b26:
      iVar9 = param_2 + (uint)bVar5 * 0x3c;
      iVar6 = iVar9 + 0x34;
      FUN_0043e040(param_1,iVar6,iVar9 + 0x44,iVar6,0,0xff);
      goto LAB_00401a64;
    }
  }
  else if (uVar7 == DAT_008025d4) {
    iVar6 = *param_3;
    *(int **)(param_2 + 4 + (uint)*(byte *)(param_2 + 0x20c) * 4) = param_3;
    if (puVar10 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)(param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
      *puVar10 = *(undefined4 *)(iVar6 + 0x5c);
      puVar10[1] = *(undefined4 *)(iVar6 + 0x60);
      puVar10[2] = *(undefined4 *)(iVar6 + 100);
      iVar9 = param_2 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c;
      iVar6 = iVar9 + 0x34;
      FUN_0043e040(param_1,iVar6,iVar9 + 0x44,iVar6,0,0xff);
      goto LAB_00401a64;
    }
  }
  else if (uVar7 == DAT_007f8cc4) {
    iVar6 = *param_3;
    *(int **)(param_2 + 4 + (uint)*(byte *)(param_2 + 0x20c) * 4) = param_3;
    if (puVar10 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)(param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
      *puVar10 = *(undefined4 *)(iVar6 + 0x10);
      puVar10[1] = *(undefined4 *)(iVar6 + 0x14);
      puVar10[2] = *(undefined4 *)(iVar6 + 0x18);
      fVar12 = (float10)FUN_005506f0(0,param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c,
                                     0x40a00000,0xffffffff);
      fVar3 = (float)fVar12;
      if ((fVar3 != 2e+06) &&
         (pfVar2 = (float *)(param_2 + 0x38 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c),
         *pfVar2 < fVar3)) {
        *pfVar2 = fVar3;
      }
      bVar5 = *(byte *)(param_2 + 0x20c);
      goto LAB_00401b26;
    }
  }
  else {
    if (uVar7 != DAT_00802460) {
      return 0;
    }
    iVar6 = *param_3;
    *(int **)(param_2 + 4 + (uint)*(byte *)(param_2 + 0x20c) * 4) = param_3;
    if (puVar10 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)(param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
      *puVar10 = *(undefined4 *)(iVar6 + 0x24);
      puVar10[1] = *(undefined4 *)(iVar6 + 0x28);
      puVar10[2] = *(undefined4 *)(iVar6 + 0x2c);
      fVar12 = (float10)FUN_005506f0(0,param_2 + 0x34 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c,
                                     0x40a00000,0xffffffff);
      fVar3 = (float)fVar12;
      if ((fVar3 != 2e+06) &&
         (pfVar2 = (float *)(param_2 + 0x38 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c),
         *pfVar2 < fVar3)) {
        *pfVar2 = fVar3;
      }
      iVar9 = param_2 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c;
      iVar6 = iVar9 + 0x34;
      FUN_0043e040(param_1,iVar6,iVar9 + 0x44,iVar6,0,0xff);
      *(int **)(param_2 + 4 + (uint)*(byte *)(param_2 + 0x20c) * 4) = param_3;
      goto LAB_00401a64;
    }
  }
  puVar11 = (undefined4 *)(param_2 + 0x24 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c);
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
LAB_00401a64:
  if (*(int *)(param_2 + 0x48 + (uint)*(byte *)(param_2 + 0x20c) * 0x3c) == 0) {
    return 0;
  }
  *(byte *)(param_2 + 0x20c) = *(byte *)(param_2 + 0x20c) + 1;
  return 1;
}

