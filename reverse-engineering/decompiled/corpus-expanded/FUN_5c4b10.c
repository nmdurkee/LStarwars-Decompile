/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4b10; label: FUN_005c4b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4b10(int param_1,int param_2,int param_3,float param_4)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  int local_34;
  float local_30;
  int local_28;
  
  iVar4 = 0;
  local_34 = -2;
  local_30 = 0.0;
  do {
    local_28 = -2;
    pfVar1 = (float *)(iVar4 * 0x10 + 8 + param_3);
    do {
      if (ABS((float)local_28) + ABS((float)local_34) <= 2.0) {
        pfVar1[-2] = (float)local_34 * (1.0 / (float)param_1);
        pfVar1[-1] = (float)local_28 * (1.0 / (float)param_2);
        fVar5 = (float10)FUN_006e8fac();
        fVar6 = (float10)FUN_006e9530();
        iVar4 = iVar4 + 1;
        *pfVar1 = (float)fVar5 / (float)fVar6;
        pfVar1[1] = 0.0;
        local_30 = (float)fVar5 / (float)fVar6 + local_30;
        pfVar1 = pfVar1 + 4;
      }
      local_28 = local_28 + 1;
    } while (local_28 < 3);
    local_34 = local_34 + 1;
  } while (local_34 < 3);
  iVar3 = 0;
  if (3 < iVar4) {
    iVar2 = (iVar4 - 4U >> 2) + 1;
    iVar3 = iVar2 * 4;
    pfVar1 = (float *)(param_3 + 0x18);
    do {
      iVar2 = iVar2 + -1;
      pfVar1[-4] = (pfVar1[-4] / local_30) * param_4;
      *pfVar1 = (*pfVar1 / local_30) * param_4;
      pfVar1[4] = (pfVar1[4] / local_30) * param_4;
      pfVar1[8] = (pfVar1[8] / local_30) * param_4;
      pfVar1 = pfVar1 + 0x10;
    } while (iVar2 != 0);
  }
  if (iVar3 < iVar4) {
    iVar4 = iVar4 - iVar3;
    pfVar1 = (float *)(iVar3 * 0x10 + 8 + param_3);
    do {
      iVar4 = iVar4 + -1;
      *pfVar1 = (*pfVar1 / local_30) * param_4;
      pfVar1 = pfVar1 + 4;
    } while (iVar4 != 0);
  }
  return;
}

