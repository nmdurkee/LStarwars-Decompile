/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x5028e0; label: FUN_005028e0
 */

void FUN_005028e0(uint *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  if (param_1[6] != 0) {
    piVar1 = (int *)(param_1[6] + param_2);
    param_1[6] = (uint)piVar1;
    if (*piVar1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar1 + param_2;
    }
    *piVar1 = iVar3;
    if ((iVar3 != 0) && (local_4 = 0, (short)piVar1[1] != 0)) {
      local_8 = 0;
      do {
        iVar6 = *piVar1 + local_8;
        iVar3 = *(int *)(iVar6 + 0x40);
        if (iVar3 != 0) {
          if (param_4 == 0) {
            *(uint *)(iVar6 + 0x40) = (param_1[3] - 1) + iVar3;
          }
          else {
            *(int *)(iVar6 + 0x40) = iVar3 + param_2;
          }
        }
        if (param_3 != 0) {
          if (*(int *)(iVar6 + 0x44) != 0) {
            uVar4 = FUN_005e91f0(*(int *)(iVar6 + 0x44),param_3,param_4,0);
            *(undefined4 *)(iVar6 + 0x44) = uVar4;
          }
          if (*(int *)(iVar6 + 0x48) != 0) {
            uVar4 = FUN_005e91f0(*(int *)(iVar6 + 0x48),param_3,param_4,0);
            *(undefined4 *)(iVar6 + 0x48) = uVar4;
          }
          if (*(int *)(iVar6 + 0x4c) != 0) {
            uVar4 = FUN_005e91f0(*(int *)(iVar6 + 0x4c),param_3,param_4,0);
            *(undefined4 *)(iVar6 + 0x4c) = uVar4;
          }
        }
        local_8 = local_8 + 100;
        local_4 = local_4 + 1;
      } while (local_4 < (int)(uint)*(ushort *)(piVar1 + 1));
    }
    if (3 < (*param_1 & 0xff)) {
      if (param_1[0x14] == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = param_1[0x14] + param_2;
      }
      param_1[0x14] = uVar5;
      if (((*piVar1 != 0) && (uVar5 != 0)) && (iVar3 = 0, (short)piVar1[1] != 0)) {
        iVar6 = 0;
        do {
          iVar2 = *(int *)(iVar6 + 4 + param_1[0x14]);
          if (iVar2 != 0) {
            uVar4 = FUN_005e91f0(iVar2,param_3,param_4,0);
            *(undefined4 *)(iVar6 + 4 + param_1[0x14]) = uVar4;
          }
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + 0x10;
        } while (iVar3 < (int)(uint)*(ushort *)(piVar1 + 1));
      }
    }
  }
  return;
}

