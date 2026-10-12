/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646d80; label: FUN_00646d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646d80(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_02920954 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00646d60,"Emitter Variation");
    if (DAT_02920954 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00646d20,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xe0),"Rand Emit X");
      FUN_00618e10(DAT_02920954,uVar1);
      uVar1 = FUN_00625150(1,&DAT_008109d8,0,FUN_00646d20,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xe4),"Rand Emit Y");
      FUN_00618e10(DAT_02920954,uVar1);
      uVar1 = FUN_00625150(2,&DAT_008109d8,0,FUN_00646d20,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xe8),"Rand Emit Z");
      FUN_00618e10(DAT_02920954,uVar1);
      FUN_006279b0(param_1,DAT_02920954);
      *(int *)(DAT_02920954 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920954 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

