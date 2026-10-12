/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c42b0; label: FUN_006c42b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c42b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_88;
  DAT_02973a3c = *(int *)(param_2 + 0xc);
  local_88 = param_1;
  iVar1 = FUN_00619250(*(int *)(param_2 + 0x1c) + *(int *)(param_1 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    if ((*(int **)(DAT_02973a3c + 8))[3] == DAT_02973ac4) {
      (**(code **)(**(int **)(DAT_02973a3c + 8) + 4))
                (*(undefined4 *)(DAT_02973a3c + 0xc),DAT_02973ac4,local_84,0x80);
    }
    uVar2 = FUN_00627a80(0xffffffff,param_2 + 0x28,0,0,FUN_006ba620,&DAT_00763b90);
    FUN_00618e10(iVar1,uVar2);
    iVar4 = 0;
    iVar3 = FUN_00650e90(0);
    while (iVar3 != 0) {
      uVar2 = FUN_00627a80(iVar4,param_2 + 0x28,0,0,FUN_006ba620,iVar3);
      FUN_00618e10(iVar1,uVar2);
      iVar4 = iVar4 + 1;
      iVar3 = FUN_00650e90(iVar4);
    }
    *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) | 1;
    FUN_006279b0(local_88,iVar1);
    FUN_006242b0(iVar1,5);
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffff7;
  }
  __security_check_cookie(local_4 ^ (uint)&local_88);
  return;
}

