/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x663f80; label: FUN_00663f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663f80(int param_1)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    DAT_02962a4c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00663f60,"Switch Menu");
    if (DAT_02962a4c != 0) {
      uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00663e50,"Switch Type...");
      FUN_00618e10(DAT_02962a4c,uVar1);
      uVar1 = FUN_00625240(0,&local_10,0,&LAB_00663da0,0xffffffff,0x81,
                           (&DAT_02924b88)[DAT_029231a8 * 0x16],"Switch ID");
      FUN_00618e10(DAT_02962a4c,uVar1);
      uVar1 = FUN_00625150(0,&local_10,0,&LAB_00663df0,0,0x41a00000,
                           (&DAT_02924b8c)[DAT_029231a8 * 0x16],"Switch Var");
      FUN_00618e10(DAT_02962a4c,uVar1);
      FUN_006279b0(param_1,DAT_02962a4c);
      *(int *)(DAT_02962a4c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962a4c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

