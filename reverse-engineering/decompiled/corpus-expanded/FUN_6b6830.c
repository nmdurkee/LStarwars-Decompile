/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b6830; label: FUN_006b6830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b6830(int *param_1,int param_2,int *param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  int local_4;
  
  iVar1 = *(int *)(param_2 + 0x510);
  iVar7 = 0;
  iVar6 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 0x40) + 4) + 0x1c) +
                  *(int *)((int)param_1 + 0x1c) * 4) / 2;
  if (param_3 != (int *)0x0) {
    iVar2 = *(int *)(iVar1 + 0x340) * *param_3;
    local_8 = 0;
    local_4 = 1;
    if (1 < *(int *)(param_2 + 0x504)) {
      param_1 = (int *)(param_2 + 0x108);
      iVar5 = iVar2;
      do {
        uVar3 = param_3[*param_1] & 0x7fff;
        iVar2 = iVar5;
        if (uVar3 == param_3[*param_1]) {
          iVar7 = *(int *)(iVar1 + 0x344 + *param_1 * 4);
          iVar2 = *(int *)(iVar1 + 0x340) * uVar3;
          FUN_006b51c0(iVar6,local_8,iVar7,iVar5,param_4);
          local_8 = iVar7;
        }
        param_1 = param_1 + 1;
        local_4 = local_4 + 1;
        iVar5 = iVar2;
      } while (local_4 < *(int *)(param_2 + 0x504));
    }
    if (3 < iVar6 - iVar7) {
      iVar5 = ((iVar6 - iVar7) - 4U >> 2) + 1;
      iVar1 = iVar7 * 4;
      iVar7 = iVar7 + iVar5 * 4;
      pfVar4 = (float *)((int)param_4 + iVar1 + 8);
      do {
        iVar5 = iVar5 + -1;
        pfVar4[-2] = *(float *)(&DAT_0081f070 + iVar2 * 4) * pfVar4[-2];
        pfVar4[-1] = pfVar4[-1] * *(float *)(&DAT_0081f070 + iVar2 * 4);
        *pfVar4 = *(float *)(&DAT_0081f070 + iVar2 * 4) * *pfVar4;
        pfVar4[1] = pfVar4[1] * *(float *)(&DAT_0081f070 + iVar2 * 4);
        pfVar4 = pfVar4 + 4;
      } while (iVar5 != 0);
    }
    while (iVar7 < iVar6) {
      iVar7 = iVar7 + 1;
      *(float *)((int)param_4 + iVar7 * 4 + -4) =
           *(float *)(&DAT_0081f070 + iVar2 * 4) * *(float *)((int)param_4 + iVar7 * 4 + -4);
    }
    return 1;
  }
  _memset(param_4,0,iVar6 * 4);
  return 0;
}

