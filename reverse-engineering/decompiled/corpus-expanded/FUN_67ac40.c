/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67ac40; label: FUN_0067ac40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0067ac40(void)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float local_1c;
  float local_18 [3];
  undefined1 local_c [12];
  
  iVar4 = DAT_0292186c;
  pfVar3 = DAT_02921838;
  if (*(char *)(DAT_0292186c + 0x88) == '\0') {
    return 1;
  }
  if ((byte)(*(char *)(DAT_0292186c + 0x88) - 2U) < 2) {
    if (0.5 <= *(float *)(DAT_0292186c + 0xb8)) {
      bVar2 = true;
      goto LAB_0067aca9;
    }
  }
  else {
    fVar1 = *(float *)(DAT_0292186c + 0xb8);
    if ((!NAN(fVar1) && 0.707 < fVar1 != (fVar1 == 0.707)) ||
       (*(float *)(DAT_0292186c + 0xb8) < -0.8)) {
      return 1;
    }
  }
  bVar2 = false;
LAB_0067aca9:
  iVar5 = FUN_006e6b90();
  local_18[0] = (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
  local_18[1] = 0.0;
  iVar5 = FUN_006e6b90();
  local_18[2] = -(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
  *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0x1c);
  *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0x20);
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 0x24);
  *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar4 + 0x28);
  *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar4 + 0x2c);
  *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar4 + 0x30);
  *(float *)(iVar4 + 0x2c) = (float)extraout_ST0;
  if (bVar2) {
    *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0xa8) * pfVar3[4] * 0.15;
    *(float *)(iVar4 + 0x30) = *(float *)(iVar4 + 0xb0) * pfVar3[4] * 0.15;
    *pfVar3 = *pfVar3 + *(float *)(iVar4 + 0xa8) * pfVar3[4] * 0.05;
    pfVar3[2] = *(float *)(iVar4 + 0xb0) * pfVar3[4] * 0.05 + pfVar3[2];
  }
  else {
    local_1c = local_18[2] * *(float *)(iVar4 + 0xbc) + local_18[0] * *(float *)(iVar4 + 0xb4);
    fVar6 = (float10)local_1c;
    if (fVar6 == extraout_ST0) {
      local_1c = (local_18[2] * pfVar3[2] + *pfVar3 * local_18[0]) / pfVar3[4];
      fVar6 = (float10)local_1c;
      if (fVar6 == extraout_ST0) {
        return 1;
      }
    }
    if (extraout_ST0 <= fVar6) {
      fVar6 = (float10)FUN_005c0240((float)fVar6);
    }
    else {
      fVar6 = (float10)FUN_005c0240((float)-fVar6);
      fVar6 = -fVar6;
    }
    iVar4 = DAT_0292186c;
    pfVar3 = DAT_02921838;
    local_1c = (float)fVar6;
    *(float *)(DAT_0292186c + 0x28) = local_1c * local_18[0] * DAT_02921838[4] + *DAT_02921838;
    *(float *)(iVar4 + 0x30) = local_1c * local_18[2] * pfVar3[4] + pfVar3[2];
  }
  do {
    FUN_0066f8f0();
    FUN_00675240();
    FUN_00678410();
    FUN_006786f0(local_c,local_c,&local_1c);
    iVar4 = DAT_0292186c;
    DAT_02947c60 = DAT_02947c60 + -1;
    if (DAT_02947c60 < 1) break;
  } while (*(char *)(DAT_0292186c + 0x88) != '\0');
  if (*(char *)(DAT_0292186c + 0x88) == '\0') {
    *(float *)(DAT_0292186c + 0x1c) =
         *(float *)(DAT_0292186c + 0x28) + *(float *)(DAT_0292186c + 0x1c);
    *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x2c) + *(float *)(iVar4 + 0x20);
    *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x30) + *(float *)(iVar4 + 0x24);
  }
  pfVar3 = DAT_02921838;
  *DAT_02921838 = (*(float *)(iVar4 + 4) - *(float *)(iVar4 + 0x1c)) + *DAT_02921838;
  pfVar3[2] = (*(float *)(iVar4 + 0xc) - *(float *)(iVar4 + 0x24)) + pfVar3[2];
  *(undefined1 *)(iVar4 + 0x88) = 1;
  *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 0x10);
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x14);
  *(undefined4 *)(iVar4 + 0x30) = *(undefined4 *)(iVar4 + 0x18);
  FUN_0067ab50(local_18,iVar4 + 0x1c);
  return 0;
}

