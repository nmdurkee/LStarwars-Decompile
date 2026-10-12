/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66ab80; label: FUN_0066ab80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066ab80(int param_1)

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
  DAT_029211f8 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0066ab60,"Info Box Style");
  if (DAT_029211f8 != 0) {
    uVar1 = FUN_00627b80(0,&local_10,DAT_02962a48 == 0,1,FUN_0066ab50,"Normal");
    FUN_00618e10(DAT_029211f8,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,DAT_02962a48 == 1,1,FUN_0066ab50,"Co-ordinates");
    FUN_00618e10(DAT_029211f8,uVar1);
  }
  FUN_006279b0(param_1,DAT_029211f8);
  *(int *)(DAT_029211f8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_029211f8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  return;
}

