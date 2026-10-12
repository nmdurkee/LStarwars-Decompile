/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdb50; label: FUN_006bdb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bdb50(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_88;
  DAT_02973aa4 = *(int *)(param_2 + 0xc);
  local_88 = param_1;
  iVar1 = FUN_00619250(*(int *)(param_2 + 0x1c) + *(int *)(param_1 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    if ((*(int **)(DAT_02973aa4 + 8))[3] == DAT_02973ac4) {
      (**(code **)(**(int **)(DAT_02973aa4 + 8) + 4))
                (*(undefined4 *)(DAT_02973aa4 + 0xc),DAT_02973ac4,local_84,0x80);
    }
    uVar2 = FUN_00627a80(0,param_2 + 0x28,0,0,FUN_006bdb00,&DAT_00763b90);
    FUN_00618e10(iVar1,uVar2);
    piVar3 = (int *)0x0;
    DAT_02973b04 = 0;
    if (0 < DAT_02973b00) {
      while ((DAT_02973b04 < DAT_02973b00 &&
             (piVar3 = (int *)(**(code **)(*(int *)(&DAT_02973b0c)[DAT_02973b04 * 2] + 0x14))(0),
             piVar3 == (int *)0x0))) {
        DAT_02973b04 = DAT_02973b04 + 1;
      }
    }
    while (piVar5 = piVar3, piVar5 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar5 + 0xc))();
      uVar2 = FUN_00627a80(piVar5,param_2 + 0x28,0,0,FUN_006bdb00,uVar2);
      FUN_00618e10(iVar1,uVar2);
      uVar2 = (**(code **)(*piVar5 + 0xc))();
      iVar4 = FUN_004f8b10(local_84,uVar2);
      if (iVar4 == 0) {
        *(undefined4 *)(iVar1 + 8) = DAT_02900c84;
      }
      piVar3 = (int *)0x0;
      if (DAT_02973b04 < DAT_02973b00) {
        while ((DAT_02973b04 < DAT_02973b00 &&
               (piVar3 = (int *)(**(code **)(*(int *)(&DAT_02973b0c)[DAT_02973b04 * 2] + 0x14))
                                          (piVar5), piVar3 == (int *)0x0))) {
          DAT_02973b04 = DAT_02973b04 + 1;
          piVar5 = (int *)0x0;
        }
      }
    }
    *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) | 1;
    FUN_006279b0(local_88,iVar1);
    FUN_006242b0(iVar1,5);
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffff7;
  }
  __security_check_cookie(local_4 ^ (uint)&local_88);
  return;
}

