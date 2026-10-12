/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a3eb0; label: FUN_004a3eb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a3eb0(float param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int local_20;
  float local_18 [2];
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = (int)param_1;
  iVar2 = *(int *)((int)param_1 + 0x790);
  iVar9 = 0;
  if (iVar2 == 0) {
    *(undefined4 *)((int)param_1 + 0xf20) = 0;
    *(undefined4 *)((int)param_1 + 0xf18) = 0;
    return 0;
  }
  if (((char)*(uint *)(iVar2 + 0xe20) < '\0') || ((*(uint *)(iVar2 + 0xe20) & 0x100) != 0)) {
    *(undefined4 *)((int)param_1 + 0xf20) = 0;
    *(undefined4 *)((int)param_1 + 0xf18) = 0;
    if (*(char *)(iVar2 + 0x7b5) != '\x1b') {
      return 0;
    }
    if (*(char *)(iVar2 + 0x7b3) != '\x01') {
      return 0;
    }
    local_c = *(float *)(iVar2 + 0x748);
    local_8 = *(float *)(iVar2 + 0x74c) -
              *(float *)((int)param_1 + 0xff0) * *(float *)((int)param_1 + 0xa8);
    local_4 = *(float *)(iVar2 + 0x750);
    fVar10 = (float10)FUN_005b3c50(&local_c,(int)param_1 + 0x5c,local_18);
    fVar1 = (float)fVar10;
    if ((0.010000001 <= fVar1) &&
       ((0.040000003 <= fVar1 ||
        (fVar10 = (float10)FUN_005c0240(fVar1),
        0.0 < (float)((fVar10 - (float10)0.10000000149011612) / (float10)0.10000000149011612))))) {
      FUN_005b3b30(local_18,local_18);
      FUN_005b3830((undefined4 *)((int)param_1 + 0xf18),local_18,0x3f800000);
    }
    *param_2 = 0x41a00000;
    return 1;
  }
  if ((*(char *)((int)param_1 + 0x7b8) == '\x04') && (iVar6 = FUN_0056e160(0x13), iVar6 != 0)) {
    uVar7 = FUN_005be2d0(*(float *)((int)param_1 + 0x80) - *(float *)(iVar2 + 0x80),
                         *(float *)((int)param_1 + 0x88) - *(float *)(iVar2 + 0x88));
    fVar1 = _DAT_007fb09c;
    *(float *)((int)param_1 + 0xf18) =
         _DAT_007fb09c * -(float)(&DAT_029899a0)[(uVar7 & 0xffff) >> 1];
    *(float *)((int)param_1 + 0xf20) =
         -(float)(&DAT_029899a0)[(int)((uVar7 & 0xffff) + 0x4000) >> 1 & 0x7fff] * fVar1;
    return 0;
  }
  if ((((DAT_0087b908 != 0) && ((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0)) &&
      ((*(uint *)(iVar2 + 0xe20) & 0x300) == 0)) && (-1 < (char)*(uint *)(iVar2 + 0xe20))) {
    param_1 = 2.25;
    local_20 = 0;
    local_c = *(float *)(iVar4 + 0x5c) - *(float *)(iVar2 + 0x5c);
    local_4 = *(float *)(iVar4 + 100) - *(float *)(iVar2 + 100);
    iVar6 = DAT_0093d504;
    if (0 < DAT_0093d500) {
      do {
        iVar8 = FUN_004a3b60(iVar4,iVar2);
        fVar1 = param_1;
        iVar5 = local_20;
        if (((iVar8 != 0) && (*(short *)(iVar6 + 0x1064) != DAT_007f1a50)) &&
           ((*(float *)(iVar6 + 0x17c) <= *(float *)(iVar4 + 0x188) &&
            (*(float *)(iVar4 + 0x17c) <= *(float *)(iVar6 + 0x188))))) {
          local_18[0] = *(float *)(iVar6 + 0x5c) - *(float *)(iVar4 + 0x5c);
          local_10 = *(float *)(iVar6 + 100) - *(float *)(iVar4 + 100);
          if ((local_18[0] * local_c + local_10 * local_4 < 0.0) ||
             (fVar1 = local_18[0] * local_18[0] + local_10 * local_10, iVar5 = iVar6,
             param_1 <= fVar1)) {
            fVar1 = param_1;
            iVar5 = local_20;
          }
        }
        local_20 = iVar5;
        param_1 = fVar1;
        iVar9 = iVar9 + 1;
        iVar6 = iVar6 + 0x10d8;
      } while (iVar9 < DAT_0093d500);
      if (local_20 != 0) {
        uVar7 = FUN_005be2d0(*(float *)(local_20 + 0x80) - *(float *)(iVar4 + 0x80),
                             *(float *)(local_20 + 0x88) - *(float *)(iVar4 + 0x88));
        uVar7 = uVar7 & 0xffff;
        fVar1 = (float)(&DAT_029899a0)[uVar7 >> 1];
        goto LAB_004a415b;
      }
    }
  }
  uVar7 = FUN_005be2d0(*(float *)(iVar4 + 0x80) - *(float *)(iVar2 + 0x80),
                       *(float *)(iVar4 + 0x88) - *(float *)(iVar2 + 0x88));
  uVar7 = uVar7 & 0xffff;
  fVar1 = (float)(&DAT_029899a0)[uVar7 >> 1];
LAB_004a415b:
  fVar3 = _DAT_007fb09c;
  *(float *)(iVar4 + 0xf18) = _DAT_007fb09c * fVar1;
  *(float *)(iVar4 + 0xf20) = fVar3 * (float)(&DAT_029899a0)[(int)(uVar7 + 0x4000) >> 1 & 0x7fff];
  return 0;
}

