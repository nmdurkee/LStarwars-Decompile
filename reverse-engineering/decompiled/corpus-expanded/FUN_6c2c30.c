/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2c30; label: FUN_006c2c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2c30(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006c2930,"Remove Duplicates");
    FUN_00618e10(iVar1,uVar2);
    FUN_006242b0(iVar1,5);
    FUN_00627930(iVar1,1);
    FUN_006279b0(param_1,iVar1);
  }
  return;
}

