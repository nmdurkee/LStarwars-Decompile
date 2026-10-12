/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b51c0; label: FUN_006b51c0
 */

void FUN_006b51c0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int local_8;
  
  iVar7 = param_3 - param_2;
  uVar3 = in_ECX - param_4;
  iVar2 = (int)uVar3 / iVar7;
  if ((int)uVar3 < 0) {
    local_8 = iVar2 + -1;
  }
  else {
    local_8 = iVar2 + 1;
  }
  uVar5 = iVar2 * iVar7 >> 0x1f;
  iVar6 = ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) - ((iVar2 * iVar7 ^ uVar5) - uVar5);
  iVar4 = 0;
  if (param_3 < param_1) {
    param_1 = param_3;
  }
  if (param_2 < param_1) {
    *(float *)(param_5 + param_2 * 4) =
         *(float *)(&DAT_0081f070 + param_4 * 4) * *(float *)(param_5 + param_2 * 4);
  }
  param_2 = param_2 + 1;
  if (3 < param_1 - param_2) {
    param_3 = ((param_1 - param_2) - 4U >> 2) + 1;
    iVar1 = param_2 * 4;
    param_2 = param_2 + param_3 * 4;
    pfVar9 = (float *)(param_5 + 8 + iVar1);
    do {
      iVar4 = iVar4 + iVar6;
      iVar1 = iVar2;
      if (iVar7 <= iVar4) {
        iVar4 = iVar4 - iVar7;
        iVar1 = local_8;
      }
      iVar4 = iVar4 + iVar6;
      pfVar9[-2] = *(float *)(&DAT_0081f070 + (param_4 + iVar1) * 4) * pfVar9[-2];
      iVar8 = iVar2;
      if (iVar7 <= iVar4) {
        iVar4 = iVar4 - iVar7;
        iVar8 = local_8;
      }
      iVar8 = param_4 + iVar1 + iVar8;
      iVar4 = iVar4 + iVar6;
      pfVar9[-1] = *(float *)(&DAT_0081f070 + iVar8 * 4) * pfVar9[-1];
      iVar1 = iVar2;
      if (iVar7 <= iVar4) {
        iVar4 = iVar4 - iVar7;
        iVar1 = local_8;
      }
      iVar8 = iVar8 + iVar1;
      iVar4 = iVar4 + iVar6;
      *pfVar9 = *(float *)(&DAT_0081f070 + iVar8 * 4) * *pfVar9;
      param_4 = iVar2;
      if (iVar7 <= iVar4) {
        iVar4 = iVar4 - iVar7;
        param_4 = local_8;
      }
      param_4 = iVar8 + param_4;
      param_3 = param_3 + -1;
      pfVar9[1] = *(float *)(&DAT_0081f070 + param_4 * 4) * pfVar9[1];
      pfVar9 = pfVar9 + 4;
    } while (param_3 != 0);
  }
  if (param_2 < param_1) {
    pfVar9 = (float *)(&DAT_0081f070 + param_4 * 4);
    do {
      iVar4 = iVar4 + iVar6;
      iVar1 = iVar2 * 4;
      if (iVar7 <= iVar4) {
        iVar4 = iVar4 - iVar7;
        iVar1 = local_8 << 2;
      }
      pfVar9 = (float *)((int)pfVar9 + iVar1);
      iVar1 = param_2 * 4;
      param_2 = param_2 + 1;
      *(float *)(param_5 + -4 + param_2 * 4) = *pfVar9 * *(float *)(param_5 + iVar1);
    } while (param_2 < param_1);
  }
  return;
}

