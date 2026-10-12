/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c3fb0; label: FUN_006c3fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c3fb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  DAT_02973a58 = *(undefined4 *)(param_2 + 0x7c);
  DAT_02973a50 = *(int *)(param_2 + 0xc);
  DAT_02973a54 = param_2;
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    piVar4 = *(int **)(DAT_02973a50 + 0x10);
    iVar2 = *piVar4;
    if (iVar2 != 0) {
      do {
        uVar3 = FUN_00627a80(piVar4,param_2 + 0x28,0,0,FUN_006c3ec0,iVar2);
        FUN_00618e10(iVar1,uVar3);
        iVar2 = piVar4[2];
        piVar4 = piVar4 + 2;
      } while (iVar2 != 0);
    }
    *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) | 1;
    FUN_006279b0(param_1,iVar1);
    FUN_006242b0(iVar1,5);
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffff7;
  }
  return;
}

