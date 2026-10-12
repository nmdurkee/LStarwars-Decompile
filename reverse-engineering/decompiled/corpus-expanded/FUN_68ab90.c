/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68ab90; label: FUN_0068ab90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068ab90(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_02921884 != -1) && (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) != 0)) {
    DAT_029629ac = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_0065ed00,"Clump Terraining");
    if (DAT_029629ac != 0) {
      uVar1 = FUN_00627bc0(0,&DAT_008109d8,(int)*(char *)(DAT_02921884 * 0x50 + 0x42 + DAT_02962a14)
                           ,1,FUN_0068ab00,"Clump Terraining");
      FUN_00618e10(DAT_029629ac,uVar1);
      iVar2 = DAT_02921884 * 0x50 + DAT_02962a14;
      if (*(char *)(iVar2 + 0x27) != '\x01') {
        uVar1 = FUN_00627bc0(0,&DAT_008109d8,(int)*(char *)(iVar2 + 0x43),2,FUN_0068ab30,
                             "Clump Tilting");
        FUN_00618e10(DAT_029629ac,uVar1);
      }
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0068ab60,0xbf800000,0x40000000,
                           *(undefined4 *)(DAT_02921884 * 0x50 + 0x44 + DAT_02962a14),
                           "Terraining Offset");
      FUN_00618e10(DAT_029629ac,uVar1);
      FUN_006279b0(param_1,DAT_029629ac);
      *(int *)(DAT_029629ac + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029629ac + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

