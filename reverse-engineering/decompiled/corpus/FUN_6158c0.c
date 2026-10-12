/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6158c0; label: FUN_006158c0
 */

void FUN_006158c0(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_34 [3];
  undefined1 local_31;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_34;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_28 = param_2;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004ef660(&local_14,*(int *)(param_1 + 8) + *(int *)(param_1 + 4),0x10);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar3 = 0;
    piVar2 = (int *)(in_ECX + 0xd838);
    while ((*piVar2 == 0 || (*piVar2 != param_2))) {
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 5;
      if (7 < iVar3) {
        __security_check_cookie(local_4 ^ (uint)auStack_34);
        return;
      }
    }
    local_2c = in_ECX + 0x10;
    cVar1 = FUN_00611cc0(local_2c);
    if (cVar1 == '\0') {
      iVar3 = in_ECX + 0xd838 + iVar3 * 0x14;
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
    else {
      iVar3 = in_ECX + 0xd838 + iVar3 * 0x14;
      *(undefined4 *)(iVar3 + 0xc) = 1;
    }
    local_30 = (uint)(cVar1 != '\0');
    *(undefined4 *)(iVar3 + 0x10) = 0;
    FUN_0053d5d0(0x20);
    local_31 = 0xb;
    if (local_20 != 0) {
      FUN_004ef660(local_18 + local_20,&local_31,1);
      iVar3 = local_18 + 1 + local_20;
      FUN_004ef660(iVar3,&local_30,4);
      if (local_24 != 0) {
        FUN_00621190(iVar3);
      }
      FUN_004ef660(local_18 + 5 + local_20,local_2c,0x10);
      local_18 = local_18 + 0x15;
    }
    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 3;
    iVar3 = local_20;
    iVar5 = local_28;
    if (local_20 == 0) {
      FUN_0060f2d0(local_24,0,local_1c,local_18,3,local_28,0,0);
    }
    else {
      *(int *)(local_20 + 0x4b0) = *(int *)(local_20 + 0x4b0) + 1;
    }
    FUN_0060efd0(local_24,iVar3,local_1c,local_18,uVar4,iVar5,uVar6,uVar7);
    if (local_20 != 0) {
      if (1 < *(uint *)(local_20 + 0x4b0)) {
        *(uint *)(local_20 + 0x4b0) = *(uint *)(local_20 + 0x4b0) - 1;
        __security_check_cookie(local_4 ^ (uint)auStack_34);
        return;
      }
      *(undefined4 *)(local_20 + 0x4b0) = 0;
    }
  }
  __security_check_cookie(local_4 ^ (uint)auStack_34);
  return;
}

