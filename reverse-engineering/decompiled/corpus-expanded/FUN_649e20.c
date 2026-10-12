/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x649e20; label: FUN_00649e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649e20(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029209d0 = FUN_00619250(0x46,0x46,300,300,DAT_02912e80,FUN_00649e00,"Debris Settings");
    if (DAT_029209d0 != 0) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006495b0,"Trail 1 Debris...");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649720,"Trail 2 Debris...");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649890,"Emitter Debris...");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006499b0,"Impact Debris...");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649bf0,"Die Debris...");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649ad0,"Impact Part...");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627bc0(0x200000,&DAT_008109d8,*(uint *)(DAT_02920970 + 0x114) >> 0x15 & 1,1,
                           FUN_006476e0,"Debris stops when Part stops");
      FUN_00618e10(DAT_029209d0,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649d30,"Debris Scale...");
      FUN_00618e10(DAT_029209d0,uVar1);
    }
    FUN_006279b0(param_1,DAT_029209d0);
    *(int *)(DAT_029209d0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209d0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

