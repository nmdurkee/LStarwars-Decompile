/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68a950; label: FUN_0068a950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068a950(int param_1)

{
  undefined4 uVar1;
  
  if ((DAT_02921884 != -1) && (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) != 0)) {
    DAT_029629a8 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0065ece0,"Clump Fading");
    if (DAT_029629a8 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0068a870,0,(float)DAT_00810a94 * 100.0,
                           *(undefined4 *)(DAT_02921884 * 0x50 + 0x38 + DAT_02962a14),
                           "Start of Fade");
      FUN_00618e10(DAT_029629a8,uVar1);
      DAT_029629c0 = DAT_02900c84;
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0068a8e0,0,(float)DAT_00810a94 * 100.0,
                           *(undefined4 *)(DAT_02921884 * 0x50 + 0x3c + DAT_02962a14),"End of Fade")
      ;
      FUN_00618e10(DAT_029629a8,uVar1);
      DAT_029629c4 = DAT_02900c84;
      FUN_0061d880(DAT_02900c84,"(%1.01f)");
      FUN_0061d900(DAT_02900c84,0x3dcccccd);
      FUN_006279b0(param_1,DAT_029629a8);
      *(int *)(DAT_029629a8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029629a8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

