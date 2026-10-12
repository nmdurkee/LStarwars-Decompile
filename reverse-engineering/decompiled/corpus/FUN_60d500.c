/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60d500; label: FUN_0060d500
 */

void FUN_0060d500(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  void *_Memory;
  uint *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *unaff_FS_OFFSET;
  undefined8 uVar7;
  uint uStack_2c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0074fc00;
  local_10 = *unaff_FS_OFFSET;
  uStack_2c = DAT_00829570 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  *unaff_FS_OFFSET = (int)&local_10;
  local_1c = *param_4;
  local_18 = param_4[1];
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(int *)(in_ECX + 0xc) - iVar4 >> 3;
  }
  if (param_3 != 0) {
    if (iVar4 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 8) - iVar4 >> 3;
    }
    uVar5 = param_3;
    puVar1 = &uStack_2c;
    if (0x1fffffffU - iVar3 < param_3) {
      uVar7 = FUN_0060d1a0();
      uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
      iVar4 = (int)uVar7;
      puVar1 = (uint *)local_14;
    }
    local_14 = (undefined1 *)puVar1;
    if (iVar4 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 8) - iVar4 >> 3;
    }
    if (uVar6 < iVar3 + uVar5) {
      if (0x1fffffff - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - iVar4 >> 3;
      }
      if (uVar6 < iVar3 + uVar5) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 3;
        }
        uVar6 = iVar4 + uVar5;
      }
      iVar4 = FUN_00605220(uVar6,0);
      local_8 = 0;
      uVar2 = FUN_0060ced0(*(undefined4 *)(in_ECX + 4),param_2,iVar4);
      uVar2 = FUN_0060cc50(uVar2,param_3,&local_1c);
      FUN_0060ced0(param_2,*(undefined4 *)(in_ECX + 8),uVar2);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
      }
      *(uint *)(in_ECX + 0xc) = iVar4 + uVar6 * 8;
      *(uint *)(in_ECX + 8) = iVar4 + (param_3 + iVar3) * 8;
      *(int *)(in_ECX + 4) = iVar4;
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar4 = *(int *)(in_ECX + 8);
    if ((uint)(iVar4 - param_2 >> 3) < uVar5) {
      FUN_0060ced0(param_2,iVar4,uVar5 * 8 + param_2);
      local_8 = 2;
      FUN_0060cc50(*(int *)(in_ECX + 8),param_3 - (*(int *)(in_ECX + 8) - param_2 >> 3),&local_1c);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar5 * 8;
      FUN_0060bf70(param_2,*(int *)(in_ECX + 8) + uVar5 * -8,&local_1c);
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar3 = iVar4 + uVar5 * -8;
    uVar2 = FUN_0060ced0(iVar3,iVar4,iVar4);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_0060c9d0(param_2,iVar3,iVar4);
    FUN_0060bf70(param_2,uVar5 * 8 + param_2,&local_1c);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

