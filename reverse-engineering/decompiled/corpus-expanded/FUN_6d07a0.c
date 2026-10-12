/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6d07a0; label: FUN_006d07a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d07a0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,"Options"
                      );
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006d05e0,"Save Data");
    FUN_00618e10(iVar1,uVar2);
    FUN_006bea80(iVar1);
    FUN_006242b0(iVar1,5);
    FUN_00627930(iVar1,1);
    FUN_006279b0(param_1,iVar1);
  }
  return;
}

