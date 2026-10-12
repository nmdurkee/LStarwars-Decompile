/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x40a570; label: FUN_0040a570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040a570(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  float fVar8;
  undefined1 *puVar9;
  float *unaff_EDI;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar6 = *(int *)(in_EAX + 0x54);
  fVar1 = (*(float *)(iVar6 + 0x38) + *(float *)(iVar6 + 0x34)) * *(float *)(iVar6 + 0x3c) * 0.5;
  iVar6 = FUN_0055f450();
  if (((*(char *)(in_EAX + 0x28b) == '\0') && (*(char *)(in_EAX + 0x7b5) != '+')) ||
     ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x40000) != 0)) {
    puVar9 = (undefined1 *)0x0;
    if (((*(char *)(in_EAX + 0x7b5) == '\x0f') && (iVar7 = *(int *)(in_EAX + 0x798), iVar7 != 0)) &&
       ((*(byte *)(iVar7 + 0x4c) & 0x10) != 0)) {
      pfVar5 = *(float **)(*(int *)(iVar7 + 0x40) + 8);
      FUN_005b3800(&local_24,pfVar5,pfVar5 + 9);
      FUN_005b3800(&local_18,pfVar5,in_EAX + 0x5c);
      fVar10 = (float10)FUN_005c0db0(&local_24);
      fVar1 = (float)((float10)1 / fVar10);
      fVar8 = pfVar5[10];
      fVar2 = pfVar5[1];
      fVar3 = pfVar5[0xb];
      fVar4 = pfVar5[2];
      *unaff_EDI = *pfVar5 - local_18 * fVar1 * ABS(pfVar5[9] - *pfVar5);
      unaff_EDI[1] = pfVar5[1] - local_14 * ABS(fVar8 - fVar2) * fVar1;
      unaff_EDI[2] = pfVar5[2] - local_10 * fVar1 * ABS(fVar3 - fVar4);
      return;
    }
    *unaff_EDI = *(float *)(in_EAX + 0x5c);
    unaff_EDI[1] = *(float *)(in_EAX + 0x60) + fVar1;
    unaff_EDI[2] = *(float *)(in_EAX + 100);
    if ((*(int *)(in_EAX + 0x1040) != 0) &&
       (iVar7 = *(int *)(*(int *)(in_EAX + 0x1040) + 4), iVar7 != 0)) {
      puVar9 = (undefined1 *)(iVar7 + 0x80);
    }
    switch(*(undefined1 *)(in_EAX + 0x7b5)) {
    case 8:
      if (*(int *)(in_EAX + 0x10cc) != 0) {
        puVar9 = (undefined1 *)(*(int *)(in_EAX + 0x10cc) + 0x1c);
      }
      break;
    case 0x1b:
      if (*(int *)(in_EAX + 0x790) != 0) {
        puVar9 = (undefined1 *)(*(int *)(in_EAX + 0x790) + 0x80);
      }
      break;
    case 0x1d:
      iVar7 = *(int *)(in_EAX + 0xcb8);
      if ((iVar7 != 0) && ((*(byte *)(iVar7 + 0x144) & 1) != 0)) {
        puVar9 = (undefined1 *)(iVar7 + 0x30);
      }
      break;
    case 0x2d:
      if (*(int *)(in_EAX + 0x798) != 0) {
        puVar9 = (undefined1 *)(*(int *)(in_EAX + 0x798) + 0x34);
      }
      break;
    case 0x46:
      iVar7 = FUN_0054f920();
      if (iVar7 != 0) {
        puVar9 = local_c;
      }
      break;
    case 0x51:
      iVar7 = FUN_004cda40(*(undefined4 *)(in_EAX + 0x798));
      puVar9 = (undefined1 *)0x0;
      if (iVar7 != 0) {
        FUN_005b3800(&local_24,iVar7,in_EAX + 0x5c);
        FUN_005b3830(&local_24,&local_24,*(undefined4 *)(*(int *)(in_EAX + 0x798) + 0x2c));
        FUN_005b37d0(&local_24,&local_24,in_EAX + 0x5c);
        *unaff_EDI = local_24;
        unaff_EDI[1] = local_20;
        unaff_EDI[2] = local_1c;
        puVar9 = (undefined1 *)0x0;
      }
      break;
    case 0x59:
      if (*(int *)(in_EAX + 0x798) != 0) {
        puVar9 = (undefined1 *)(*(int *)(in_EAX + 0x798) + 0x28);
      }
    }
    if (((*(short *)(in_EAX + 0x1064) == DAT_007f1974) ||
        (*(short *)(in_EAX + 0x1064) == DAT_007f1978)) && (*(int *)(iVar6 + 0x46ec) != 0)) {
      local_18 = (*(float *)(*(int *)(iVar6 + 0x46ec) + 0x48c) + *unaff_EDI) * 0.5;
      local_14 = unaff_EDI[1];
      local_10 = (*(float *)(*(int *)(iVar6 + 0x46ec) + 0x494) + unaff_EDI[2]) * 0.5;
    }
    else if (puVar9 == (undefined1 *)0x0) {
      return;
    }
    FUN_0054a100();
  }
  else {
    if (*(char *)(in_EAX + 0x28b) == '\0') {
      *unaff_EDI = *(float *)(in_EAX + 0x1c0);
      unaff_EDI[1] = *(float *)(in_EAX + 0x1c4);
      fVar8 = *(float *)(in_EAX + 0x1c8);
    }
    else {
      *unaff_EDI = *(float *)(in_EAX + 0x5c);
      unaff_EDI[1] = *(float *)(in_EAX + 0x60);
      fVar8 = *(float *)(in_EAX + 100);
    }
    unaff_EDI[2] = fVar8;
    unaff_EDI[1] = unaff_EDI[1] + fVar1;
    if (((DAT_00951288 != 0) && ((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0)) &&
       (0.0 < *(float *)(in_EAX + 0x1010))) {
      if (0.5 <= 1.0 - *(float *)(in_EAX + 0x1010) * 0.5) {
        iVar6 = FUN_006e6b90();
        fVar10 = extraout_ST1 -
                 (extraout_ST1 -
                 ((float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] + extraout_ST1) *
                 extraout_ST0);
      }
      else {
        iVar6 = FUN_006e6b90();
        fVar10 = (float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
      }
      *unaff_EDI = *unaff_EDI + (float)fVar10 * *(float *)(in_EAX + 0x68);
      unaff_EDI[2] = (float)fVar10 * *(float *)(in_EAX + 0x70) + unaff_EDI[2];
      return;
    }
  }
  return;
}

