/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x592820; label: FUN_00592820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00592820(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  if (param_1 == 0) {
    return param_2;
  }
  iVar3 = param_2 * 0x28;
  iVar2 = param_2 << 5;
  local_8 = 0;
  do {
    if (param_3 <= local_8) {
      return param_2;
    }
    param_2 = param_2 + -1;
    iVar2 = iVar2 + -0x20;
    iVar3 = iVar3 + -0x28;
    if (param_2 < 0) {
      param_2 = param_2 + param_3;
      iVar2 = iVar2 + param_3 * 0x20;
      iVar3 = iVar3 + param_3 * 0x28;
    }
    if ((((param_5 == 2) || (iVar1 = FUN_0055f450(), iVar1 == 0)) || (DAT_00951364 == 0)) ||
       (*(int *)(iVar1 + 300) != DAT_00951364)) {
LAB_005928dd:
      if ((((*(ushort *)(*(int *)(param_1 + 0x24 + param_5 * 4) + 0x12 + iVar3) & 0x180) == 0) ||
          (iVar1 = FUN_0055c880(), iVar1 != 0)) &&
         (iVar1 = (**(code **)(param_1 + 0x170))(*(int *)(param_1 + 0x24 + param_5 * 4) + iVar3),
         iVar1 != 0)) {
        return param_2;
      }
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x5120 + param_5 * 4);
      if (iVar1 != 0) {
        if (*(char *)(*(int *)(param_1 + param_5 * 4) + 4) == '\0') {
          iVar1 = *(int *)(iVar2 + 0x14 + iVar1);
        }
        else {
          iVar1 = FUN_005cfac0(iVar2 + 4 + iVar1);
        }
        if (iVar1 != 0) goto LAB_005928dd;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}

