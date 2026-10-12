/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a6ce0; label: FUN_005a6ce0
 */

int FUN_005a6ce0(float param_1,float *param_2,float param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  int local_20;
  
  iVar10 = (int)param_1;
  iVar11 = 0;
  if ((param_1 != 0.0) && (param_2 != (float *)0x0)) {
    piVar1 = (int *)((int)param_1 + 0x46c0);
    fVar2 = *param_2;
    iVar12 = *(int *)((int)param_1 + 0x46bc);
    local_20 = 0;
    fVar3 = param_2[1];
    fVar4 = param_2[2];
    fVar5 = *param_2;
    fVar6 = param_2[1];
    fVar7 = param_2[2];
    param_1 = 1e+09;
    if (0 < *piVar1) {
      do {
        uVar8 = *(uint *)(iVar12 + 200);
        if (((((((uVar8 & 0x40000) != 0) && ((uVar8 & 0x1000000) != 0)) && ((uVar8 & 0x100) == 0))
             && ((pfVar9 = *(float **)(iVar12 + 0x58), fVar2 - param_3 <= *pfVar9 &&
                 (*pfVar9 <= fVar5 + param_3)))) &&
            ((fVar4 - param_3 <= pfVar9[2] &&
             ((pfVar9[2] <= param_3 + fVar7 && (fVar3 - param_3 <= pfVar9[1])))))) &&
           (pfVar9[1] <= param_3 + fVar6)) {
          fVar13 = (float10)FUN_005b3c50(param_2,pfVar9,0);
          if ((float)fVar13 < param_1) {
            param_1 = (float)fVar13;
            local_20 = iVar12;
          }
        }
        iVar11 = iVar11 + 1;
        iVar12 = iVar12 + 0xd4;
      } while (iVar11 < *(int *)(iVar10 + 0x46c0));
    }
    return local_20;
  }
  return 0;
}

