/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646c50; label: FUN_00646c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646c50(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_0291f70c = FUN_00619250(0x46,0x46,0xfa,200,DAT_02912e80,FUN_00646c30,"Radii");
    if (DAT_0291f70c != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00644700,0,(float)DAT_008101bc * 25.0,
                           *(undefined4 *)(DAT_02920970 + 0x15c),"CutOff Rad");
      FUN_00618e10(DAT_0291f70c,uVar1);
      FUN_006279b0(param_1,DAT_0291f70c);
      *(int *)(DAT_0291f70c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0291f70c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

