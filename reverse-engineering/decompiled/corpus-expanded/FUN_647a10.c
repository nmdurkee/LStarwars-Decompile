/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647a10; label: FUN_00647a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647a10(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029208c0 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_006479f0,"Emitter Vel");
    if (DAT_029208c0 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_006479d0,-((float)DAT_008101bc * 10.0),
                           (float)DAT_008101bc * 20.0,*(undefined4 *)(DAT_02920970 + 0xc4),
                           "Emitter Vel");
      FUN_00618e10(DAT_029208c0,uVar1);
      FUN_006279b0(param_1,DAT_029208c0);
      *(int *)(DAT_029208c0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029208c0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

