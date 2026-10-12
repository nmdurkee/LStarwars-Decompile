/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d2b0; label: FUN_0060d2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060d2b0(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *unaff_FS_OFFSET;
  undefined8 uVar8;
  uint uStack_2c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  int local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0074fbe0;
  local_10 = *unaff_FS_OFFSET;
  uStack_2c = DAT_00829570 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  *unaff_FS_OFFSET = (int)&local_10;
  local_1c = *param_4;
  local_18 = param_4[1];
  iVar5 = *(int *)(in_ECX + 4);
  if (iVar5 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(int *)(in_ECX + 0xc) - iVar5 >> 3;
  }
  if (param_3 != 0) {
    if (iVar5 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar5 >> 3;
    }
    uVar6 = param_3;
    puVar1 = &uStack_2c;
    if (0x1fffffffU - iVar4 < param_3) {
      uVar8 = FUN_0060d0b0();
      uVar6 = (uint)((ulonglong)uVar8 >> 0x20);
      iVar5 = (int)uVar8;
      puVar1 = (uint *)local_14;
    }
    local_14 = (undefined1 *)puVar1;
    if (iVar5 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar5 >> 3;
    }
    if (uVar7 < iVar4 + uVar6) {
      if (0x1fffffff - (uVar7 >> 1) < uVar7) {
        uVar7 = 0;
      }
      else {
        uVar7 = uVar7 + (uVar7 >> 1);
      }
      if (iVar5 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - iVar5 >> 3;
      }
      if (uVar7 < iVar4 + uVar6) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 3;
        }
        uVar7 = iVar5 + uVar6;
      }
      iVar4 = FUN_006051c0(uVar7,0);
      local_8 = 0;
      uVar2 = FUN_0060cea0(*(undefined4 *)(in_ECX + 4),param_2,iVar4);
      uVar2 = FUN_0060cc10(uVar2,param_3,&local_1c);
      FUN_0060cea0(param_2,*(undefined4 *)(in_ECX + 8),uVar2);
      local_8 = 0xffffffff;
      iVar5 = *(int *)(in_ECX + 4);
      if (iVar5 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - iVar5 >> 3;
      }
      if (iVar5 != 0) {
        FUN_006e85b0(iVar5);
      }
      *(uint *)(in_ECX + 0xc) = iVar4 + uVar7 * 8;
      *(uint *)(in_ECX + 8) = iVar4 + (param_3 + iVar3) * 8;
      *(int *)(in_ECX + 4) = iVar4;
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar5 = *(int *)(in_ECX + 8);
    if ((uint)(iVar5 - param_2 >> 3) < uVar6) {
      FUN_0060cea0(param_2,iVar5,uVar6 * 8 + param_2);
      local_8 = 2;
      FUN_0060cc10(*(int *)(in_ECX + 8),param_3 - (*(int *)(in_ECX + 8) - param_2 >> 3),&local_1c);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar6 * 8;
      FUN_0060bf40(param_2,*(int *)(in_ECX + 8) + uVar6 * -8,&local_1c);
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar4 = iVar5 + uVar6 * -8;
    uVar2 = FUN_0060cea0(iVar4,iVar5,iVar5);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_0060c980(param_2,iVar4,iVar5);
    FUN_0060bf40(param_2,uVar6 * 8 + param_2,&local_1c);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

