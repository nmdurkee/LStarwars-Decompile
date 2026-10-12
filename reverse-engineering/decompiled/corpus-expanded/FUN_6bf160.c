/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bf160; label: FUN_006bf160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bf160(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_c;
  int iStack_8;
  
  DAT_02973ae4 = *(int *)(param_2 + 0xc);
  iVar2 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78);
  if (iVar2 != 0) {
    (**(code **)(**(int **)(DAT_02973ae4 + 8) + 4))
              (*(undefined4 *)(DAT_02973ae4 + 0xc),DAT_02973acc,&local_c,0);
    iVar1 = param_2 + 0x28;
    uVar3 = FUN_00627a80(0xffffffff,iVar1,0,0,FUN_006bf0e0,&DAT_00763b90);
    FUN_00618e10(iVar2,uVar3);
    piVar4 = (int *)FUN_006bd880(0,FUN_006befb0);
    while (piVar4 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar4 + 0xc))();
      uVar3 = FUN_00627a80(piVar4,iVar1,0,0,FUN_006bf0e0,uVar3);
      FUN_00618e10(iVar2,uVar3);
      piVar5 = (int *)FUN_006bd880(piVar4,FUN_006befb0);
      iVar6 = FUN_005d0450(piVar4 + 6,&stack0xffffffe4);
      piVar4 = piVar5;
      param_2 = iStack_8;
      if (iVar6 != 0) {
        *(undefined4 *)(iVar2 + 8) = DAT_02900c84;
      }
    }
    FUN_00619060(iVar2);
    *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | 1;
    FUN_006279b0(local_c,iVar2);
    FUN_006242b0(iVar2,5);
    FUN_00627930(iVar2,0x1e);
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffff7;
  }
  return;
}

