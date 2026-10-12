/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x663e50; label: FUN_00663e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663e50(int param_1)

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
  DAT_02962a50 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_00663e30,"Switch Type");
  if (DAT_02962a50 != 0) {
    uVar1 = FUN_00627b80(0,&local_10,(&DAT_02924b84)[DAT_029231a8 * 0x16] == 0,1,FUN_00663d40,
                         &DAT_00763b90);
    FUN_00618e10(DAT_02962a50,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,(&DAT_02924b84)[DAT_029231a8 * 0x16] == 1,1,FUN_00663d40,
                         "Global Switch");
    FUN_00618e10(DAT_02962a50,uVar1);
    FUN_006279b0(param_1,DAT_02962a50);
    *(int *)(DAT_02962a50 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962a50 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

