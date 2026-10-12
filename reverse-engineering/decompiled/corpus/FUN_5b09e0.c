/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5b09e0; label: FUN_005b09e0
 */

int FUN_005b09e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = param_2;
  iVar6 = 0;
  if (param_2 == 0) {
    return 0;
  }
  local_4 = 0;
  if (0 < *(int *)(param_2 + 0x50f4)) {
    local_8 = 0;
    do {
      iVar4 = 0;
      iVar5 = *(int *)(iVar1 + 0x50ec) + local_8;
      if (0 < *(int *)(iVar5 + 0x14)) {
        param_2 = 0;
        do {
          iVar2 = FUN_004f8b10(*(int *)(iVar5 + 0x10) + param_2,param_4);
          if (iVar2 == 0) {
            uVar3 = FUN_0055a020(*(undefined4 *)(iVar1 + 0x2ac8),0xffffffff,iVar5);
            *(undefined4 *)(param_1 + iVar6 * 4) = uVar3;
            iVar6 = iVar6 + 1;
            if (param_3 <= iVar6) {
              return -1;
            }
          }
          param_2 = param_2 + 0x44;
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar5 + 0x14));
      }
      local_8 = local_8 + 0x30;
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(iVar1 + 0x50f4));
  }
  return iVar6;
}

