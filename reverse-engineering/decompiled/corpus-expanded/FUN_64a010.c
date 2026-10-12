/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64a010; label: FUN_0064a010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064a010(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029209cc = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00649ff0,"Emitter Settings");
    if (DAT_029209cc != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00647a10,"Emitter Vel...");
      FUN_00618e10(DAT_029209cc,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00647b60,"Gravity...");
      FUN_00618e10(DAT_029209cc,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00647480,"Random Start...");
      FUN_00618e10(DAT_029209cc,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00646d80,"Random Emit...");
      FUN_00618e10(DAT_029209cc,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644770,"Emits per Sec...");
      FUN_00618e10(DAT_029209cc,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006477b0,"Emitter Timing...");
      FUN_00618e10(DAT_029209cc,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00646c50,"Radii...");
      FUN_00618e10(DAT_029209cc,uVar1);
    }
    FUN_006279b0(param_1,DAT_029209cc);
    *(int *)(DAT_029209cc + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209cc + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

