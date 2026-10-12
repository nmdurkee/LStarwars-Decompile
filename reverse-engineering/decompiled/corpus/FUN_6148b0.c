/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6148b0; label: FUN_006148b0
 */

undefined4
FUN_006148b0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_15;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  uVar5 = param_5;
  iVar2 = param_4;
  iVar1 = param_3;
  uVar3 = param_2;
  local_c = param_3;
  local_8 = param_4;
  local_4 = param_5;
  local_10 = param_2;
  local_14 = in_ECX;
  if (param_3 == 0) {
    FUN_0060f2d0();
  }
  else {
    *(int *)(param_3 + 0x4b0) = *(int *)(param_3 + 0x4b0) + 1;
  }
  local_15 = (undefined1)param_1;
  if (iVar1 != 0) {
    iVar2 = iVar2 + -1;
    local_8 = iVar2;
    FUN_004ef660(iVar1 + iVar2,&local_15,1);
  }
  local_15 = 7;
  if (iVar1 != 0) {
    iVar2 = iVar2 + -1;
    local_8 = iVar2;
    FUN_004ef660(iVar1 + iVar2,&local_15,1);
  }
  if (param_6 == 0) {
    uVar6 = 3;
    iVar4 = iVar1;
    if (iVar1 == 0) {
      FUN_0060f2d0(uVar3,0,iVar2,uVar5,3);
    }
    else {
      *(int *)(iVar1 + 0x4b0) = *(int *)(iVar1 + 0x4b0) + 1;
    }
    FUN_0060f190(uVar3,iVar4,iVar2,uVar5,uVar6);
    (**(code **)(local_14 + (param_1 * 3 + 0x35ac) * 4))(&param_2);
  }
  else if (*(char *)(param_6 + 0xc) == '\0') {
    FUN_0053d460(&local_10);
    FUN_0060efd0();
  }
  else {
    (**(code **)(local_14 + (param_1 * 3 + 0x35ac) * 4))(&param_2);
  }
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x4b0) < 2) {
      *(undefined4 *)(iVar1 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
    }
  }
  if (param_3 != 0) {
    if (1 < *(uint *)(param_3 + 0x4b0)) {
      *(uint *)(param_3 + 0x4b0) = *(uint *)(param_3 + 0x4b0) - 1;
      return 1;
    }
    *(undefined4 *)(param_3 + 0x4b0) = 0;
  }
  return 1;
}

