/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x65ed90; label: FUN_0065ed90
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
  DAT_029629b4 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_0065ed70,"Dpad Mode");
  if (DAT_029629b4 != 0) {
    uVar1 = FUN_00627b80(0,&local_10,DAT_029629f4 == 0,1,&LAB_0065ed60,"Clump Size");
    FUN_00618e10(DAT_029629b4,uVar1);
    uVar1 = FUN_00627b80(1,&local_10,DAT_029629f4 == 1,1,&LAB_0065ed60,"Clump Tilt");
    FUN_00618e10(DAT_029629b4,uVar1);
    FUN_006279b0(param_1,DAT_029629b4);
    *(int *)(DAT_029629b4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029629b4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

