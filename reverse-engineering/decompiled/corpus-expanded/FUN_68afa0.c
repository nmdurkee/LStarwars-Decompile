/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68afa0; label: FUN_0068afa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068afa0(int param_1)

{
  undefined4 uVar1;
  
  DAT_029629b0 = FUN_00619250(0x46,0x46,200,0xfa,DAT_02912e80,FUN_0065ed40,"Clump Mode");
  if (DAT_029629b0 != 0) {
    if ((DAT_02921884 == -1) || (*(char *)(DAT_02921884 * 0x50 + 0x27 + DAT_02962a14) != '\x03')) {
      uVar1 = FUN_00627b80(1,&DAT_008109d8,DAT_00810a88 == 1,1,FUN_0068af70,"Wind Mode");
      FUN_00618e10(DAT_029629b0,uVar1);
      uVar1 = FUN_00627b80(2,&DAT_008109d8,DAT_00810a88 == 2,1,FUN_0068af70,"Faded Static Mode");
    }
    else {
      uVar1 = FUN_00627a80(1,&DAT_008109e8,DAT_00810a88 == 1,0,0,"Wind Mode");
      FUN_00618e10(DAT_029629b0,uVar1);
      uVar1 = FUN_00627a80(2,&DAT_008109e8,DAT_00810a88 == 2,0,0,"Faded Static Mode");
    }
    FUN_00618e10(DAT_029629b0,uVar1);
    if ((DAT_02921884 == -1) || (*(char *)(DAT_02921884 * 0x50 + 0x27 + DAT_02962a14) == '\x03')) {
      uVar1 = FUN_00627b80(3,&DAT_008109d8,DAT_00810a88 == 3,1,FUN_0068af70,"Individual FS Mode");
    }
    else {
      uVar1 = FUN_00627a80(3,&DAT_008109e8,DAT_00810a88 == 3,0,0,"Individual FS Mode");
    }
    FUN_00618e10(DAT_029629b0,uVar1);
    FUN_006279b0(param_1,DAT_029629b0);
    *(int *)(DAT_029629b0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029629b0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

