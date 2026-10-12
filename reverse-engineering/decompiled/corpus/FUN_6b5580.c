/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b5580; label: FUN_006b5580
 */

void FUN_006b5580(int *param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar5 = *param_1;
  iVar1 = param_1[param_2 * 8 + -7];
  iVar7 = 0;
  iVar9 = 0;
  iVar10 = 0;
  iVar8 = 0;
  iVar6 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (0 < param_2) {
    param_1 = param_1 + 3;
    iVar6 = 0;
    do {
      iVar7 = iVar7 + param_1[-1];
      iVar9 = iVar9 + *param_1;
      iVar10 = iVar10 + param_1[1];
      iVar8 = iVar8 + param_1[3];
      iVar6 = iVar6 + param_1[4];
      param_1 = param_1 + 8;
      param_2 = param_2 + -1;
      local_24 = iVar7;
      local_20 = iVar9;
      local_1c = iVar10;
    } while (param_2 != 0);
  }
  iVar7 = *param_3;
  if (-1 < iVar7) {
    local_20 = local_20 + iVar7;
    local_1c = local_1c + iVar5 * iVar5;
    local_24 = local_24 + iVar5;
    iVar8 = iVar8 + iVar7 * iVar5;
    iVar6 = iVar6 + 1;
  }
  iVar7 = *param_4;
  if (-1 < iVar7) {
    local_24 = local_24 + iVar1;
    local_20 = local_20 + iVar7;
    local_1c = local_1c + iVar1 * iVar1;
    iVar8 = iVar8 + iVar7 * iVar1;
    iVar6 = iVar6 + 1;
  }
  if (iVar6 == 0) {
    *param_3 = 0;
    *param_4 = 0;
  }
  else {
    dVar4 = (double)local_24;
    dVar3 = 1.0 / ((double)iVar6 * (double)local_1c - dVar4 * dVar4);
    dVar2 = ((double)local_1c * (double)local_20 - (double)iVar8 * dVar4) * dVar3;
    dVar3 = dVar3 * ((double)iVar6 * (double)iVar8 - (double)local_20 * dVar4);
    FUN_006eafc0(dVar3 * (double)iVar5 + dVar2 + 0.5);
    iVar5 = FUN_006e6b90();
    *param_3 = iVar5;
    FUN_006eafc0((double)iVar1 * dVar3 + dVar2 + 0.5);
    iVar5 = FUN_006e6b90();
    *param_4 = iVar5;
    if (0x3ff < *param_3) {
      *param_3 = 0x3ff;
    }
    if (0x3ff < *param_4) {
      *param_4 = 0x3ff;
    }
    if (*param_3 < 0) {
      *param_3 = 0;
    }
    if (*param_4 < 0) {
      *param_4 = 0;
      return;
    }
  }
  return;
}

