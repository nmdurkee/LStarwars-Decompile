/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b3960; label: FUN_006b3960
 */

int * FUN_006b3960(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *_Dst;
  int iVar6;
  int *piVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  float10 extraout_ST0;
  float10 fVar11;
  float local_70;
  int local_6c;
  int local_58;
  int local_54;
  
  piVar1 = (int *)*param_1;
  iVar2 = piVar1[3];
  iVar3 = piVar1[2];
  iVar4 = (piVar1[1] - *piVar1) / iVar3;
  piVar5 = (int *)FUN_006a1550();
  iVar8 = 0;
  if (0 < param_3) {
    do {
      _Dst = (void *)FUN_006a1550();
      piVar5[iVar8] = (int)_Dst;
      _memset(_Dst,0,iVar4 * 4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_3);
  }
  local_54 = 0;
  if (0 < iVar4) {
    fVar11 = (float10)0;
    local_6c = 0;
    do {
      iVar8 = *piVar1;
      if (0 < param_3) {
        piVar7 = piVar5;
        local_58 = param_3;
        do {
          local_70 = (float)fVar11;
          if (0 < iVar3) {
            pfVar9 = (float *)(*(int *)((param_2 - (int)piVar5) + (int)piVar7) +
                              (iVar8 + local_6c) * 4);
            iVar10 = iVar3;
            do {
              if (local_70 < ABS(*pfVar9)) {
                local_70 = ABS(*pfVar9);
              }
              FUN_006eafc0((double)(*pfVar9 + 0.5));
              pfVar9 = pfVar9 + 1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            fVar11 = (float10)0;
          }
          iVar10 = 0;
          if (0 < iVar2 + -1) {
            pfVar9 = (float *)(piVar1 + 0x185);
            do {
              if ((local_70 <= pfVar9[-0x40]) &&
                 (((float10)*pfVar9 < fVar11 ||
                  (iVar6 = FUN_006e6b90(), fVar11 = extraout_ST0, (float)iVar6 < *pfVar9)))) break;
              iVar10 = iVar10 + 1;
              pfVar9 = pfVar9 + 1;
            } while (iVar10 < iVar2 + -1);
          }
          iVar6 = *piVar7;
          piVar7 = piVar7 + 1;
          local_58 = local_58 + -1;
          *(int *)(iVar6 + local_54 * 4) = iVar10;
        } while (local_58 != 0);
      }
      local_6c = local_6c + iVar3;
      local_54 = local_54 + 1;
    } while (local_54 < iVar4);
  }
  param_1[10] = param_1[10] + 1;
  return piVar5;
}

