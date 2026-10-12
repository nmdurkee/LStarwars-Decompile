/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74d8a0; label: FUN_0074d8a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074d8a0(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int extraout_ECX;
  uint extraout_EDX;
  uint uVar5;
  uint uVar6;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0074fca0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  param_4 = (undefined4 *)*param_4;
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(int *)(in_ECX + 0xc) - iVar2 >> 2;
  }
  if (param_3 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    uVar5 = param_3;
    if (0x3fffffffU - iVar1 < param_3) {
      FUN_0074d7e0();
      iVar2 = extraout_ECX;
      uVar5 = extraout_EDX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    if (uVar6 < iVar1 + uVar5) {
      if (0x3fffffff - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
      }
      if (uVar6 < iVar1 + uVar5) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
        }
        uVar6 = iVar2 + uVar5;
      }
      iVar1 = FUN_0074b880(uVar6,0);
      local_8 = 0;
      uVar3 = FUN_0074d660(*(undefined4 *)(in_ECX + 4),param_2,iVar1);
      uVar3 = FUN_0074d760(uVar3,param_3,&param_4);
      FUN_0074d660(param_2,*(undefined4 *)(in_ECX + 8),uVar3);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - iVar2 >> 2;
      }
      if (iVar2 != 0) {
        FUN_006e85b0(iVar2);
      }
      *(uint *)(in_ECX + 0xc) = iVar1 + uVar6 * 4;
      *(uint *)(in_ECX + 8) = iVar1 + (param_3 + iVar4) * 4;
      *(int *)(in_ECX + 4) = iVar1;
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar2 = *(int *)(in_ECX + 8);
    if ((uint)(iVar2 - param_2 >> 2) < uVar5) {
      FUN_0074d660(param_2,iVar2,uVar5 * 4 + param_2);
      local_8 = 2;
      FUN_0074d760(*(int *)(in_ECX + 8),param_3 - (*(int *)(in_ECX + 8) - param_2 >> 2),&param_4);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar5 * 4;
      FUN_0074c910(param_2,*(int *)(in_ECX + 8) + uVar5 * -4,&param_4);
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar1 = iVar2 + uVar5 * -4;
    uVar3 = FUN_0074d660(iVar1,iVar2,iVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_0074c930(param_2,iVar1,iVar2);
    FUN_0074c910(param_2,uVar5 * 4 + param_2,&param_4);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

