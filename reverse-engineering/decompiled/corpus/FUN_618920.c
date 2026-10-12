/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x618920; label: FUN_00618920
 */

void FUN_00618920(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 local_10 [16];
  
  iVar1 = FUN_006e6b90();
  iVar1 = iVar1 + param_1 * 0x10;
  if (DAT_02912eb8 == 0) {
    iVar2 = FUN_006e6b90(param_4 * 8,local_10,(&DAT_02900c70)[DAT_02912e90]);
    FUN_005dbd70(iVar1,param_2 * 8,(iVar2 - iVar1) + param_1 * 0x10);
    return;
  }
  return;
}

