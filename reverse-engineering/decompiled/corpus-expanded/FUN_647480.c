/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647480; label: FUN_00647480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647480(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_02913a4c = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00647460,"Random Start");
    if (DAT_02913a4c != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647420,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xd4),"Rand Start X");
      FUN_00618e10(DAT_02913a4c,uVar1);
      uVar1 = FUN_00625150(1,&DAT_008109d8,0,FUN_00647420,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xd8),"Rand Start Y");
      FUN_00618e10(DAT_02913a4c,uVar1);
      uVar1 = FUN_00625150(2,&DAT_008109d8,0,FUN_00647420,0,(float)DAT_008101bc * 5.0,
                           *(undefined4 *)(DAT_02920970 + 0xdc),"Rand Start Z");
      FUN_00618e10(DAT_02913a4c,uVar1);
      FUN_006279b0(param_1,DAT_02913a4c);
      *(int *)(DAT_02913a4c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02913a4c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

