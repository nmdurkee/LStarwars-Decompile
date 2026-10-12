/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fdfd0; label: FUN_005fdfd0
 */

void FUN_005fdfd0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  iVar2 = 0;
  do {
    iVar1 = *(int *)(param_1 + iVar2 * 4);
    if (iVar1 == -1) {
      iVar1 = 1;
    }
    iVar1 = FUN_005e5310(iVar1);
    FUN_006e5630(iVar2,*(undefined4 *)(iVar1 + 0x24));
    FUN_006e54e0(iVar2,1,1);
    FUN_006e54e0(iVar2,2,1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  FUN_007412e0(0x60,&local_c);
  return;
}

