/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64ccb0; label: FUN_0064ccb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064ccb0(int param_1)

{
  undefined4 uVar1;
  undefined *puVar2;
  code *pcVar3;
  char *pcVar4;
  
  DAT_02920958 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00648ac0,"Data Menu");
  if (DAT_02920958 == 0) {
    return;
  }
  if (DAT_00810194 == -1) {
    uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Type Name...");
  }
  else {
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644410,"Type Name...");
  }
  FUN_00618e10(DAT_02920958,uVar1);
  if (DAT_00810194 == -1) {
    uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Copy Type");
    FUN_00618e10(DAT_02920958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Delete Type");
    FUN_00618e10(DAT_02920958,uVar1);
    pcVar4 = "Move Type";
    pcVar3 = (code *)0x0;
    puVar2 = &DAT_008109e8;
  }
  else {
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006445d0,"Copy Type");
    FUN_00618e10(DAT_02920958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,&LAB_0064b950,"Delete Type");
    FUN_00618e10(DAT_02920958,uVar1);
    if ((&DAT_02913b0b)[DAT_00810194 * 0x178] == '\0') {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00648a50,"Move Type to Level List");
      goto LAB_0064ce42;
    }
    pcVar4 = "Move Type to General List";
    pcVar3 = FUN_00648a50;
    puVar2 = &DAT_008109d8;
  }
  uVar1 = FUN_00627a80(1,puVar2,0,0,pcVar3,pcVar4);
LAB_0064ce42:
  FUN_00618e10(DAT_02920958,uVar1);
  uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006485a0,"Save General List");
  FUN_00618e10(DAT_02920958,uVar1);
  uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00648740,"Save Level List");
  FUN_00618e10(DAT_02920958,uVar1);
  uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00648270,"Save All");
  FUN_00618e10(DAT_02920958,uVar1);
  uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0064c7b0,"Load All");
  FUN_00618e10(DAT_02920958,uVar1);
  FUN_006279b0(param_1,DAT_02920958);
  *(int *)(DAT_02920958 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_02920958 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  return;
}

