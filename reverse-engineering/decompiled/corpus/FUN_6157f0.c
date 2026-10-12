/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6157f0; label: FUN_006157f0
 */

void FUN_006157f0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_11;
  int local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  FUN_0053d5d0(0x20);
  local_11 = 5;
  if (local_c != 0) {
    FUN_004ef660(local_4 + local_c,&local_11,1);
    iVar1 = local_4 + 1 + local_c;
    FUN_004ef660(iVar1,&stack0x00000004,2);
    if (local_10 != 0) {
      FUN_00621180(iVar1);
    }
    local_4 = local_4 + 3;
  }
  uVar2 = 3;
  iVar1 = local_c;
  if (local_c == 0) {
    FUN_0060f2d0(local_10,0,local_8,local_4,3);
  }
  else {
    *(int *)(local_c + 0x4b0) = *(int *)(local_c + 0x4b0) + 1;
  }
  FUN_0060f190(local_10,iVar1,local_8,local_4,uVar2);
  if (local_c != 0) {
    if (1 < *(uint *)(local_c + 0x4b0)) {
      *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(local_c + 0x4b0) = 0;
  }
  return;
}

