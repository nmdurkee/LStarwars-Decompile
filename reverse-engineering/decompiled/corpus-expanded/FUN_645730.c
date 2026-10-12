/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x645730; label: FUN_00645730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00645730(int param_1)

{
  undefined4 uVar1;
  
  DAT_029209a8 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00645710,"Emitter Type");
  if (DAT_029209a8 != 0) {
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00645390,"General List...");
    FUN_00618e10(DAT_029209a8,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006455e0,"Level List...");
    FUN_00618e10(DAT_029209a8,uVar1);
    FUN_006279b0(param_1,DAT_029209a8);
    *(int *)(DAT_029209a8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209a8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

