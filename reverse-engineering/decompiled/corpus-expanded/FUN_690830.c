/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x690830; label: FUN_00690830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00690830(void)

{
  undefined4 uVar1;
  
  DAT_02962958 = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,FUN_0065d440,"Options");
  if (DAT_02962958 != 0) {
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065d0a0,"Plank Instance...");
    FUN_00618e10(DAT_02962958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065cf40,"Post Instance...");
    FUN_00618e10(DAT_02962958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065d230,"Plank Counts...");
    FUN_00618e10(DAT_02962958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065d370,"Dpad Mode...");
    FUN_00618e10(DAT_02962958,uVar1);
    if (DAT_02947c14 == -1) {
      uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Bridge Properties...");
    }
    else {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00689a00,"Bridge Properties...");
    }
    FUN_00618e10(DAT_02962958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065cd30,"Save Bridges");
    FUN_00618e10(DAT_02962958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006906c0,"Load Bridges");
    FUN_00618e10(DAT_02962958,uVar1);
  }
  return;
}

