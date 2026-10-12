/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x689a00; label: FUN_00689a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00689a00(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02947c14 != -1) {
    DAT_0296296c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065d320,"Bridge Properties");
    if (DAT_0296296c != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006898e0,0,0x3f800000,
                           (&DAT_02947dc0)[DAT_02947c14 * 0x11],"Tension");
      FUN_00618e10(DAT_0296296c,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00689910,0,0x3f800000,
                           (&DAT_02947dc4)[DAT_02947c14 * 0x11],&DAT_0076e440);
      FUN_00618e10(DAT_0296296c,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00689940,0xbdcccccd,0x3e4ccccd,
                           (&DAT_02947dc8)[DAT_02947c14 * 0x11],"Gravity");
      FUN_00618e10(DAT_0296296c,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00689970,0,0x41200000,
                           (&DAT_02947dcc)[DAT_02947c14 * 0x11],"Plrweight");
      FUN_00618e10(DAT_0296296c,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006899a0,0,0x40000000,
                           (&DAT_02947dd0)[DAT_02947c14 * 0x11],"Rope Height");
      FUN_00618e10(DAT_0296296c,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006899d0,0,0x41200000,
                           (&DAT_02947dd4)[DAT_02947c14 * 0x11],"Stability");
      FUN_00618e10(DAT_0296296c,uVar1);
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006897d0,"Rope Colour...");
      FUN_00618e10(DAT_0296296c,uVar1);
      FUN_006279b0(param_1,DAT_0296296c);
      *(int *)(DAT_0296296c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0296296c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

