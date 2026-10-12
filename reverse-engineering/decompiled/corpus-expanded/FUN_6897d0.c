/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x6897d0; label: FUN_006897d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006897d0(int param_1)

{
  undefined4 uVar1;
  
  DAT_02962970 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065d300,"Rope Colour");
  if (DAT_02962970 != 0) {
    uVar1 = FUN_00624e20(0,&DAT_008109d8,&LAB_006896e0,"Rope Colour");
    FUN_00618e10(DAT_02962970,uVar1);
    FUN_0061ad60(DAT_02900c84,(float)(byte)(&DAT_02947dd8)[DAT_02947c14 * 0x44] / 255.0,
                 (float)(byte)(&DAT_02947dd9)[DAT_02947c14 * 0x44] / 255.0,
                 (float)(byte)(&DAT_02947dda)[DAT_02947c14 * 0x44] / 255.0);
    FUN_006279b0(param_1,DAT_02962970);
    *(int *)(DAT_02962970 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962970 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

