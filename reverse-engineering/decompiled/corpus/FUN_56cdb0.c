/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56cdb0; label: FUN_0056cdb0
 */

undefined4 FUN_0056cdb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x50a4) != 0) {
    return 0;
  }
  FUN_006217e0();
  iVar1 = FUN_006217e0();
  iVar2 = 0;
  *(int *)(param_1 + 0x50a4) = iVar1;
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x50a0) + iVar1,8);
      FUN_00621900(iVar1 + 8 + *(int *)(param_1 + 0x50a0));
      FUN_00621900(iVar1 + 0x14 + *(int *)(param_1 + 0x50a0));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x24;
    } while (iVar2 < *(int *)(param_1 + 0x50a4));
  }
  return 1;
}

