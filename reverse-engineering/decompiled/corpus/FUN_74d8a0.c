/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74d8a0; label: FUN_0074d8a0
 */

void FUN_0074d8a0(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int extraout_ECX;
  uint extraout_EDX;
  uint uVar4;
  uint uVar5;
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
    uVar5 = 0;
  }
  else {
    uVar5 = *(int *)(in_ECX + 0xc) - iVar2 >> 2;
  }
  if (param_3 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    uVar4 = param_3;
    if (0x3fffffffU - iVar1 < param_3) {
      FUN_0074d7e0();
      iVar2 = extraout_ECX;
      uVar4 = extraout_EDX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    if (uVar5 < iVar1 + uVar4) {
      if (0x3fffffff - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
      }
      if (uVar5 < iVar1 + uVar4) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
        }
        uVar5 = iVar2 + uVar4;
      }
      iVar2 = FUN_0074b880(uVar5,0);
      local_8 = 0;
      uVar3 = FUN_0074d660(*(undefined4 *)(in_ECX + 4),param_2,iVar2);
      uVar3 = FUN_0074d760(uVar3,param_3,&param_4);
      FUN_0074d660(param_2,*(undefined4 *)(in_ECX + 8),uVar3);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
      }
      *(uint *)(in_ECX + 0xc) = iVar2 + uVar5 * 4;
      *(uint *)(in_ECX + 8) = iVar2 + (param_3 + iVar1) * 4;
      *(int *)(in_ECX + 4) = iVar2;
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar2 = *(int *)(in_ECX + 8);
    if ((uint)(iVar2 - param_2 >> 2) < uVar4) {
      FUN_0074d660(param_2,iVar2,uVar4 * 4 + param_2);
      local_8 = 2;
      FUN_0074d760(*(int *)(in_ECX + 8),param_3 - (*(int *)(in_ECX + 8) - param_2 >> 2),&param_4);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar4 * 4;
      FUN_0074c910(param_2,*(int *)(in_ECX + 8) + uVar4 * -4,&param_4);
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar1 = iVar2 + uVar4 * -4;
    uVar3 = FUN_0074d660(iVar1,iVar2,iVar2);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_0074c930(param_2,iVar1,iVar2);
    FUN_0074c910(param_2,uVar4 * 4 + param_2,&param_4);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

