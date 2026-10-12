/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x691730; label: FUN_00691730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00691730(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  
  DAT_0296298c = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,&LAB_0065f8c0,"Options");
  if (DAT_0296298c != 0) {
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065ea70,"Base Instance Select...");
    FUN_00618e10(DAT_0296298c,uVar2);
    if (DAT_02921884 == -1) {
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Change Instance...");
    }
    else {
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0068a0d0,"Change Instance...");
    }
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0068afa0,"Clump Mode...");
    FUN_00618e10(DAT_0296298c,uVar2);
    if (DAT_02921884 == -1) {
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Clump Properties...");
    }
    else {
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0068ad00,"Clump Properties...");
    }
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065ed90,"Dpad Mode...");
    FUN_00618e10(DAT_0296298c,uVar2);
    if (DAT_02921884 == -1) {
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Copy Clump");
    }
    else {
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065f660,"Copy Clump");
    }
    FUN_00618e10(DAT_0296298c,uVar2);
    if (DAT_00810a90 == -1) {
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Discard Copy");
    }
    else {
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065f6a0,"Discard Copy");
    }
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,&LAB_0065f530,"Save Grass");
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006915e0,"Load Grass");
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0065f720,"Super Scale...");
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_008109d8,DAT_029629d4,1,FUN_0065f880,"Instance Filter");
    FUN_00618e10(DAT_0296298c,uVar2);
    uVar2 = FUN_00627c00(0,&DAT_008109d8,FUN_0065f8a0,"Filter String: ");
    FUN_00618e10(DAT_0296298c,uVar2);
    pcVar3 = s_GRASS_00810a78;
    pcVar4 = (char *)(DAT_02900c84 + 0x4c);
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    *(undefined2 *)(DAT_02900c84 + 0x15a) = 0xf;
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0068ba50,"Global Options...");
    FUN_00618e10(DAT_0296298c,uVar2);
  }
  return;
}

