/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65ed90; label: FUN_0065ed90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ed90(int param_1)

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
  DAT_029629b4 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065ed70,"Dpad Mode");
  if (DAT_029629b4 != 0) {
    uVar1 = FUN_00627b80(0,&local_10,DAT_029629f4 == 0,1,FUN_0065ed60,"Clump Size");
    FUN_00618e10(DAT_029629b4,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,DAT_029629f4 == 1,1,FUN_0065ed60,"Clump Tilt");
    FUN_00618e10(DAT_029629b4,uVar1);
    FUN_006279b0(param_1,DAT_029629b4);
    *(int *)(DAT_029629b4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029629b4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

