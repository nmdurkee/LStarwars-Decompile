/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x6462e0; label: FUN_006462e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006462e0(int param_1)

{
  undefined4 uVar1;
  
  DAT_029209b4 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_006462c0,"Instance Select");
  if ((DAT_029209b4 != 0) && (DAT_02920970 != 0)) {
    uVar1 = FUN_00627bc0(9999,&DAT_008109d8,*(short *)(DAT_02920970 + 0x90) == 9999,2,FUN_006457f0,
                         s_NULL_instance_008101c4);
    FUN_00618e10(DAT_029209b4,uVar1);
    DAT_02920a88 = DAT_02900c84;
    if (*(char *)(DAT_02920970 + 0xb3) == '\x01') {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00645980,"World Scene...");
    }
    else {
      uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"World Scene...");
    }
    FUN_00618e10(DAT_029209b4,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00645bb0,"Things Scene...");
    FUN_00618e10(DAT_029209b4,uVar1);
    if ((DAT_0291f66c == 0) && (DAT_0291f788 == 0)) {
      uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Instance Orphans/Dupes...");
    }
    else {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006460e0,"Instance Orphans/Dupes...");
    }
    FUN_00618e10(DAT_029209b4,uVar1);
    uVar1 = FUN_00627b80(0,&DAT_008109d8,*(char *)(DAT_02920970 + 0xb1) == '\0',1,FUN_006462a0,
                         "Random Distribution");
    FUN_00618e10(DAT_029209b4,uVar1);
    uVar1 = FUN_00627b80(1,&DAT_008109d8,*(char *)(DAT_02920970 + 0xb1) == '\x01',1,FUN_006462a0,
                         "Sequential Distribution");
    FUN_00618e10(DAT_029209b4,uVar1);
    FUN_006279b0(param_1,DAT_029209b4);
    *(int *)(DAT_029209b4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209b4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

