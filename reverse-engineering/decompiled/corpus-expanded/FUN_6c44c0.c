/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c44c0; label: FUN_006c44c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c44c0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,
                       "Editor List");
  if (iVar2 != 0) {
    for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      uVar3 = (**(code **)(*piVar1 + 8))();
      uVar3 = FUN_00627a80(piVar1,&DAT_0081f9a0,0,0,FUN_006bc970,uVar3);
      FUN_00618e10(iVar2,uVar3);
    }
    FUN_006242b0(iVar2,5);
    FUN_00627930(iVar2,1);
    FUN_006279b0(param_1,iVar2);
  }
  return;
}

