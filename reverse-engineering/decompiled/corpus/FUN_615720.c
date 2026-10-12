/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x615720; label: FUN_00615720
 */

void FUN_00615720(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_11;
  int local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  FUN_0053d5d0(0x20);
  local_11 = 4;
  if (local_c != 0) {
    FUN_004ef660(local_4 + local_c,&local_11,1);
    iVar1 = local_4 + 1 + local_c;
    FUN_004ef660(iVar1,&param_1,2);
    if (local_10 != 0) {
      FUN_00621180(iVar1);
    }
    local_4 = local_4 + 3;
  }
  uVar5 = 0;
  uVar4 = 0;
  uVar2 = 3;
  iVar1 = local_c;
  uVar3 = param_2;
  if (local_c == 0) {
    FUN_0060f2d0(local_10,0,local_8,local_4,3,param_2,0,0);
  }
  else {
    *(int *)(local_c + 0x4b0) = *(int *)(local_c + 0x4b0) + 1;
  }
  FUN_0060efd0(local_10,iVar1,local_8,local_4,uVar2,uVar3,uVar4,uVar5);
  if (local_c != 0) {
    if (1 < *(uint *)(local_c + 0x4b0)) {
      *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(local_c + 0x4b0) = 0;
  }
  return;
}

