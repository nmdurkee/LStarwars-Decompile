/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c88c0; label: FUN_004c88c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c88c0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  int aiStack_400 [256];
  
  if (*(char *)(param_2 + 0x7b5) == 'T') {
    if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) == 0)
       || (iVar8 = FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0), iVar8 != 0)) {
      *(float *)(param_2 + 0x77c) = *(float *)(param_2 + 0x77c) + _DAT_00925018;
      if ((*(float *)(param_2 + 0x784) < 0.2) &&
         ((*(uint *)(*(int *)(param_2 + 0xca4) + 4) & DAT_00802280) != 0)) {
        *(undefined4 *)(param_2 + 0x784) = 0x3e4ccccd;
      }
      fVar1 = *(float *)(param_2 + 0x784) - _DAT_00925018;
      *(float *)(param_2 + 0x784) = fVar1;
      if (fVar1 <= 0.0) {
        *(undefined1 *)(param_2 + 0x7b5) = 0xff;
        return;
      }
      fVar1 = *(float *)(param_2 + 0x77c);
      if ((!NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5)) &&
         (iVar8 = *(int *)(param_1 + 0x50c8), iVar8 != 0)) {
        fVar1 = *(float *)(param_2 + 0x80);
        iVar9 = 0;
        fVar2 = *(float *)(param_2 + 0x84);
        fVar3 = *(float *)(param_2 + 0x88);
        fVar4 = *(float *)(param_2 + 0x80);
        fVar5 = *(float *)(param_2 + 0x84);
        fVar6 = *(float *)(param_2 + 0x88);
        iVar10 = 0;
        if (0 < *(int *)(param_1 + 0x50c0)) {
          do {
            uVar7 = *(uint *)(iVar8 + 0x94);
            if (((((((uVar7 & 1) == 0) && ((uVar7 & 0x800000) != 0)) && ((uVar7 & 0x4000) != 0)) &&
                 ((*(uint *)(iVar8 + 0x98) & 0x40) != 0)) &&
                (((((*(uint *)(iVar8 + 0x98) & 0x20) == 0 || (DAT_0087baf0 != 0)) &&
                  ((fVar1 - 3.0 <= *(float *)(iVar8 + 0x4c) &&
                   ((*(float *)(iVar8 + 0x4c) <= fVar4 + 3.0 &&
                    (fVar3 - 3.0 <= *(float *)(iVar8 + 0x54))))))) &&
                 (*(float *)(iVar8 + 0x54) <= fVar6 + 3.0)))) &&
               ((((fVar2 - 3.0 <= *(float *)(iVar8 + 0x50) &&
                  (*(float *)(iVar8 + 0x50) <= fVar5 + 3.0)) &&
                 (fVar11 = (float10)FUN_005b3c50((float *)(iVar8 + 0x4c),(float *)(param_2 + 0x80),0
                                                ), fVar11 <= (float10)9.0)) && (iVar9 < 0x100)))) {
              aiStack_400[iVar9] = iVar8;
              iVar9 = iVar9 + 1;
            }
            iVar10 = iVar10 + 1;
            iVar8 = iVar8 + 0x114;
          } while (iVar10 < *(int *)(param_1 + 0x50c0));
          if ((0 < iVar9) && (iVar8 = FUN_0062c350(0x40a00000,_DAT_00925018), 0 < iVar8)) {
            iVar8 = FUN_0054fa60(1,6,1,0,1);
            FUN_00567800(aiStack_400[iVar8 / ((int)(0xffff / (longlong)iVar9) + 1)]);
          }
        }
      }
    }
  }
  else if (((*(char *)(param_2 + 0x281) != '\0') && (iVar8 = FUN_005620f0(param_2), iVar8 != 0)) &&
          ((*(uint *)(*(int *)(param_2 + 0xca4) + 4) & DAT_00802280) != 0)) {
    *(undefined1 *)(param_2 + 0x7b5) = 0x54;
    *(undefined4 *)(param_2 + 0x77c) = 0;
    *(undefined2 *)(param_2 + 0x7aa) = 0x9c;
    *(undefined4 *)(param_2 + 0x784) = 0x3e99999a;
    return;
  }
  return;
}

