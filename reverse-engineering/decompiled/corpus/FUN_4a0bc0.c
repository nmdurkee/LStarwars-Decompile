/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a0bc0; label: FUN_004a0bc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a0bc0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int iVar6;
  float10 fVar7;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(unaff_ESI + 0xe04) == -1) {
    return;
  }
  if ((((*(char *)(unaff_ESI + 0x7b5) == '\x1b') && ((*(uint *)(unaff_ESI + 0xe20) & 0x100) != 0))
      && ((*(uint *)(unaff_ESI + 0xe20) & 0x400) == 0)) &&
     (iVar3 = *(int *)(unaff_ESI + 0x790), iVar3 != 0)) {
    FUN_00635970(*(int *)(unaff_ESI + 0xe04),1);
    fVar7 = (float10)FUN_005becc0(iVar3 + 0x80,(float *)(unaff_ESI + 0x80),&local_c);
    fVar1 = (float)(fVar7 * (float10)0.5);
    FUN_00635890(*(undefined4 *)(unaff_ESI + 0xe04),fVar1,(float)((float10)fVar1 + (float10)0.5));
    local_30 = 0.0;
    iVar3 = FUN_0054fa60();
    if (iVar3 < 0x8000) {
      local_2c = 2.0;
    }
    else {
      local_2c = 0.25;
    }
    local_28 = local_2c;
    FUN_00635900(*(undefined4 *)(unaff_ESI + 0xe04),&local_30,0);
    local_24 = *(float *)(unaff_ESI + 0x80) + local_c * 0.5;
    local_20 = local_8 * 0.5 + *(float *)(unaff_ESI + 0x84);
    local_1c = local_4 * 0.5 + *(float *)(unaff_ESI + 0x88);
    FUN_00635840(*(undefined4 *)(unaff_ESI + 0xe04),&local_24);
    return;
  }
  if (*(float *)(unaff_ESI + 0xd3c) <= 0.0) {
    return;
  }
  if (*(char *)(unaff_ESI + 0xe34) == '\0') {
    return;
  }
  iVar3 = 0;
  local_24 = DAT_0093b0cc;
  local_20 = (float)DAT_0093b0d0;
  local_1c = (float)DAT_0093b0d4;
  iVar5 = 0;
  do {
    if ((*(char *)(unaff_ESI + 0x28c) != '\0') && ((*(uint *)(unaff_ESI + 0xe20) & 0x8000000) != 0))
    {
      iVar6 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
      iVar4 = (int)*(char *)(iVar6 + 0x100 + iVar5);
      if (((iVar4 != -1) &&
          ((*(int *)(*(int *)(unaff_ESI + 0x50) + 0x14 + iVar4 * 4) != 0 &&
           (iVar6 = (int)*(char *)(iVar6 + 0x101 + iVar5), iVar6 != -1)))) &&
         (*(int *)(*(int *)(unaff_ESI + 0x50) + 0x14 + iVar6 * 4) != 0)) {
        FUN_005b37d0(&local_24,&local_24,iVar4 * 0x40 + 0x834 + unaff_ESI);
        FUN_005b37d0(&local_24,&local_24,iVar6 * 0x40 + 0x834 + unaff_ESI);
        iVar3 = iVar3 + 2;
      }
    }
    iVar5 = iVar5 + 2;
  } while (iVar5 < 8);
  if (iVar3 < 1) {
    return;
  }
  FUN_005b3830(&local_24,&local_24,1.0 / (float)iVar3);
  FUN_00635970(*(undefined4 *)(unaff_ESI + 0xe04),1);
  fVar1 = *(float *)(unaff_ESI + 0xd44) * 3.0 * *(float *)(unaff_ESI + 0xd3c) *
          *(float *)(unaff_ESI + 0xa8);
  FUN_00635890(*(undefined4 *)(unaff_ESI + 0xe04),fVar1 + 0.25,fVar1 + 0.5);
  iVar3 = FUN_0054fa60();
  if (iVar3 < 0x8000) {
    fVar1 = 0.003921569;
  }
  else {
    fVar1 = 0.007843138;
  }
  if (*(char *)(unaff_ESI + 0x280) == -1) {
LAB_004a0eac:
    if (*(short *)(unaff_ESI + 0x1064) != DAT_007f1968) {
      iVar3 = (int)*(char *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x117);
      if (iVar3 == -1) goto LAB_004a1061;
      goto LAB_004a1017;
    }
    local_30 = (float)DAT_007fb102;
    local_2c = (float)DAT_007fb103;
    local_28 = (float)DAT_007fb104;
    local_18 = (float)DAT_007fb112;
    local_14 = (float)DAT_007fb113;
    local_10 = (float)DAT_007fb114;
    fVar7 = (float10)FUN_005b7d30(_DAT_0092505c,0x40000000);
    fVar2 = (float)(((float10)(float)(&DAT_029899a0)
                                     [(uint)(int)ROUND(fVar7 * (float10)0.5 * (float10)65536.0) >> 1
                                      & 0x7fff] + (float10)1.0) * (float10)0.5);
    local_30 = fVar2 * (local_18 - local_30) + local_30;
    local_2c = local_2c + fVar2 * (local_14 - local_2c);
    local_28 = local_28 + (local_10 - local_28) * fVar2;
  }
  else {
    iVar3 = FUN_0056e160(0x19);
    if (iVar3 == 0) {
      if ((*(char *)(unaff_ESI + 0x280) == -1) || (iVar3 = FUN_0041af30(), iVar3 == 0))
      goto LAB_004a0eac;
      iVar3 = 3;
    }
    else {
      iVar3 = 0;
    }
LAB_004a1017:
    iVar3 = iVar3 * 0x10;
    local_30 = (float)(byte)(&DAT_007fb0f2)[iVar3];
    local_2c = (float)(byte)(&DAT_007fb0f3)[iVar3];
    local_28 = (float)(byte)(&DAT_007fb0f4)[iVar3];
  }
  local_2c = local_2c * fVar1;
  local_30 = fVar1 * local_30;
  local_28 = local_28 * fVar1;
LAB_004a1061:
  FUN_00635900(*(undefined4 *)(unaff_ESI + 0xe04),&local_30,0);
  FUN_00635900(*(undefined4 *)(unaff_ESI + 0xe04),&local_30,0);
  FUN_00635840(*(undefined4 *)(unaff_ESI + 0xe04),&local_24);
  return;
}

