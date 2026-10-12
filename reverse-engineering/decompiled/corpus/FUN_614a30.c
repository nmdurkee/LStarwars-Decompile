/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x614a30; label: FUN_00614a30
 */

undefined4
FUN_00614a30(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  uVar4 = 0;
  iVar3 = FUN_00612b60(param_1);
  if (iVar3 != 0) {
    local_18 = FUN_006be780(*(undefined4 *)(iVar3 + 0x10));
    iVar5 = param_5;
    iVar2 = param_4;
    iVar1 = param_3;
    local_18 = local_18 & 0xffff;
    local_14 = (uint)*(ushort *)(iVar3 + 2);
    local_c = param_4;
    local_8 = param_5;
    local_4 = param_6;
    local_10 = param_3;
    if (param_4 == 0) {
      FUN_0060f2d0();
    }
    else {
      *(int *)(param_4 + 0x4b0) = *(int *)(param_4 + 0x4b0) + 1;
      iVar3 = param_4 + param_5 + -2;
      FUN_004ef660(iVar3,&local_18,2);
      if (iVar1 != 0) {
        FUN_00621180(iVar3);
      }
      iVar5 = iVar5 + -4;
      local_8 = iVar5;
      FUN_004ef660(iVar2 + iVar5,&local_14,2);
      if (iVar1 != 0) {
        FUN_00621180(iVar2 + iVar5);
      }
    }
    iVar3 = param_2;
    if (iVar2 != 0) {
      iVar5 = iVar5 + -1;
      local_8 = iVar5;
      FUN_004ef660(iVar2 + iVar5,&param_2,1);
    }
    param_2 = CONCAT31(param_2._1_3_,8);
    if (iVar2 != 0) {
      local_8 = iVar5 + -1;
      FUN_004ef660(iVar2 + local_8,&param_2,1);
    }
    if (param_7 == 0) {
      FUN_0053d460(&local_10);
      FUN_0060f190();
      (**(code **)(in_ECX + (iVar3 * 3 + 0x35ac) * 4))(param_1,&param_3);
    }
    else if (*(char *)(param_7 + 0xc) == '\0') {
      FUN_0053d460(&local_10);
      FUN_0060efd0();
    }
    else {
      (**(code **)(in_ECX + (iVar3 * 3 + 0x35ac) * 4))(param_1,&param_3);
    }
    uVar4 = 1;
    if (iVar2 != 0) {
      if (*(uint *)(iVar2 + 0x4b0) < 2) {
        *(undefined4 *)(iVar2 + 0x4b0) = 0;
      }
      else {
        *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
      }
    }
  }
  if (param_4 != 0) {
    if (1 < *(uint *)(param_4 + 0x4b0)) {
      *(uint *)(param_4 + 0x4b0) = *(uint *)(param_4 + 0x4b0) - 1;
      return uVar4;
    }
    *(undefined4 *)(param_4 + 0x4b0) = 0;
  }
  return uVar4;
}

