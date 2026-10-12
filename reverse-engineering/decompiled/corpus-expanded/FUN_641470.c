/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x641470; label: FUN_00641470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00641470(void)

{
  undefined4 uVar1;
  
  DAT_02913958 = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,FUN_0063acf0,"Burnout Menu");
  if (DAT_02913958 != 0) {
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00639f00,"Level Defaults...");
    FUN_00618e10(DAT_02913958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0063a780,"Radius Defaults...");
    FUN_00618e10(DAT_02913958,uVar1);
    if ((DAT_0291396c == 0) || (*(int *)(DAT_0291396c + 0x554) == -1)) {
      uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Burnset Properties...");
    }
    else {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0063a9a0,"Burnset Properties...");
    }
    FUN_00618e10(DAT_02913958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0063a4f0,"Transitions...");
    FUN_00618e10(DAT_02913958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,&LAB_0063abb0,"Save Burnouts");
    FUN_00618e10(DAT_02913958,uVar1);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006412f0,"Load Burnouts");
    FUN_00618e10(DAT_02913958,uVar1);
  }
  return;
}

