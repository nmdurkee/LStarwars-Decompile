/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x537370; label: FUN_00537370
 */

void FUN_00537370(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float10 fVar10;
  undefined1 local_18 [12];
  float afStack_c [3];
  
  iVar5 = param_3;
  iVar6 = *(int *)(param_3 + 0xcc);
  if (*(int *)(param_3 + 0xcc) == 0) {
    iVar6 = param_3;
  }
  param_3 = iVar6;
  if ((*(byte *)(iVar5 + 0x1ea) & 1) == 0) {
    uVar4 = *(undefined4 *)(iVar5 + 8);
    if ((*(int *)(iVar5 + 4) != 0) &&
       (iVar6 = FUN_00512fc0("Initialise",*(int *)(iVar5 + 4)), iVar6 != 0)) {
      FUN_005145a0(iVar5,iVar6);
      FUN_0052cc90(param_1,param_2,iVar5,iVar5,0);
      FUN_005145a0(iVar5,uVar4);
    }
    *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) | 0x10000;
  }
  if (param_7 == 0) goto LAB_005376dc;
  FUN_005371a0(param_1,param_2,iVar5,param_4,param_5);
  *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) & 0xfff7fbf7;
  *(undefined4 *)(iVar5 + 0x1e4) = 0;
  if (((char)*(uint *)(param_2 + 0x1fc) < '\0') && ((*(uint *)(param_2 + 0x1fc) & 0x100) == 0)) {
    *(undefined1 *)(iVar5 + 0x139) = 0;
    *(undefined4 *)(iVar5 + 0x184) = 0;
    *(undefined4 *)(iVar5 + 0x104) = *(undefined4 *)(param_2 + 0x5c);
    *(undefined4 *)(iVar5 + 0x108) = *(undefined4 *)(param_2 + 0x60);
    uVar4 = *(undefined4 *)(param_2 + 100);
    *(uint *)(iVar5 + 0x1ec) = *(uint *)(iVar5 + 0x1ec) & 0xfffffffe;
    *(undefined4 *)(iVar5 + 0x10c) = uVar4;
    *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) & 0x3f0fffff;
    goto LAB_005376dc;
  }
  if ((DAT_009238b4 != (code *)0x0) && (iVar6 = (*DAT_009238b4)(param_2), iVar6 != 0)) {
    return;
  }
  FUN_005d0480(param_2 + 0x20c);
  *(uint *)(param_2 + 0x1fc) = *(uint *)(param_2 + 0x1fc) & 0xfffbffff;
  if ((param_1 != 0) && (*(int *)(param_3 + 4) != 0)) {
    FUN_0052cc90(param_1,param_2,iVar5,param_3,param_5);
  }
  *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) & 0x3f0fffff;
  uVar9 = *(uint *)(iVar5 + 0x1e8);
  *(uint *)(iVar5 + 0x1ec) = *(uint *)(iVar5 + 0x1ec) & 0xfffffffe;
  *(undefined4 *)(iVar5 + 0x1f8) = 0;
  if ((uVar9 & 0x10000000) != 0) {
    uVar8 = uVar9 >> 0x1a & 3;
    if (uVar8 == 1) {
      if (*(byte *)(iVar5 + 0x138) != 0xff) {
        iVar7 = (uint)*(byte *)(iVar5 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
        iVar6 = iVar7 + 0x30;
        iVar7 = iVar7 + 0x20;
LAB_00537546:
        FUN_0052fcb0(iVar5,iVar7,0,iVar6,1,0);
      }
    }
    else if (uVar8 == 2) {
      iVar7 = *(int *)(iVar5 + 0xa4);
      if (iVar7 != 0) {
        iVar6 = iVar7 + 0x20;
        iVar7 = iVar7 + 0x10;
        goto LAB_00537546;
      }
    }
    else {
      *(uint *)(iVar5 + 0x1e8) = uVar9 & 0xefffffff;
    }
  }
  FUN_00530240(param_1,iVar5,param_2,param_4);
  uVar9 = *(uint *)(iVar5 + 0x1e8) >> 0x1a & 3;
  if ((((uVar9 != 0) && (*(int *)(iVar5 + 0x184) == 0)) && (0.0 < *(float *)(iVar5 + 0x1f0))) &&
     ((*(uint *)(param_2 + 0x1f8) & 0x400) != 0)) {
    if (uVar9 == 1) {
      if (*(byte *)(iVar5 + 0x138) == 0xff) goto LAB_005376dc;
      iVar6 = (uint)*(byte *)(iVar5 + 0x138) * 0xa4 + 0x20 + *(int *)(param_1 + 0x18);
    }
    else {
      if ((uVar9 != 2) || (*(int *)(iVar5 + 0xa4) == 0)) goto LAB_005376dc;
      iVar6 = *(int *)(iVar5 + 0xa4) + 0x10;
    }
    if (iVar6 != 0) {
      pfVar1 = (float *)(param_2 + 0x5c);
      fVar10 = (float10)FUN_005b3cf0(iVar6,pfVar1,local_18);
      fVar2 = (float)fVar10;
      uVar9 = *(uint *)(iVar5 + 0x1e8);
      fVar3 = *(float *)(iVar5 + 0x1f0);
      if ((uVar9 & 0x10000000) == 0) {
        if (fVar3 * fVar3 < fVar2) {
          fVar3 = *(float *)(iVar5 + 0x1f0) + 0.5;
          if (fVar2 <= fVar3 * fVar3) {
            afStack_c[0] = *(float *)(iVar5 + 0x104) - *pfVar1;
            afStack_c[1] = 0.0;
            afStack_c[2] = *(float *)(iVar5 + 0x10c) - *(float *)(param_2 + 100);
            fVar10 = (float10)FUN_005b39e0(afStack_c,local_18);
            if (fVar10 < (float10)0) {
              *(float *)(iVar5 + 0x104) = *pfVar1;
              *(undefined4 *)(iVar5 + 0x108) = *(undefined4 *)(param_2 + 0x60);
              uVar4 = *(undefined4 *)(param_2 + 100);
              *(float *)(iVar5 + 0x110) = (float)(float10)0;
              *(undefined4 *)(iVar5 + 0x10c) = uVar4;
            }
          }
          else {
            *(uint *)(iVar5 + 0x1e8) = uVar9 | 0x10000000;
          }
        }
      }
      else if (fVar2 < fVar3 * fVar3) {
        *(uint *)(iVar5 + 0x1e8) = uVar9 & 0xefffffff;
      }
    }
  }
LAB_005376dc:
  fVar2 = 0.0;
  if (*(float *)(iVar5 + 0x110) != 0.0) {
    fVar2 = *(float *)(iVar5 + 0x120);
  }
  param_2 = param_2 + 0x5c;
  iVar6 = iVar5 + 0x104;
  if (param_6 == 0) {
    fVar10 = (float10)FUN_005bed80(iVar6,param_2,local_18);
    fVar3 = (float)fVar10;
    if (fVar2 + *(float *)(iVar5 + 0x120) + *(float *)(iVar5 + 0x110) < fVar3) {
      if ((*(float *)(iVar5 + 0x120) == 0.0) || (fVar3 == 0.0)) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = *(float *)(iVar5 + 0x120) / fVar3;
      }
      FUN_005b3830(local_18,local_18,fVar3);
      FUN_005b37d0(iVar5 + 0x114,param_2,local_18);
      return;
    }
    fVar2 = fVar2 + *(float *)(iVar5 + 0x110);
    if ((fVar2 == 0.0) || (fVar3 == 0.0)) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = fVar2 / fVar3;
    }
    FUN_005b3830(local_18,local_18,fVar2);
  }
  else {
    fVar10 = (float10)FUN_005becc0(iVar6,param_2,local_18);
    fVar3 = (float)fVar10;
    if (fVar2 + *(float *)(iVar5 + 0x120) + *(float *)(iVar5 + 0x110) < fVar3) {
      if ((*(float *)(iVar5 + 0x120) == 0.0) || (fVar3 == 0.0)) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = *(float *)(iVar5 + 0x120) / fVar3;
      }
      FUN_005b3830(local_18,local_18,fVar3);
      FUN_005b37d0(iVar5 + 0x114,param_2,local_18);
      return;
    }
    fVar2 = fVar2 + *(float *)(iVar5 + 0x110);
    if ((fVar2 == 0.0) || (fVar3 == 0.0)) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = fVar2 / fVar3;
    }
    FUN_005b3830(local_18,local_18,fVar2);
  }
  FUN_005b3800(iVar5 + 0x114,iVar6,local_18);
  return;
}

