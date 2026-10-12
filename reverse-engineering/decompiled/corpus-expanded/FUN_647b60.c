/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647b60; label: FUN_00647b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647b60(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_029208cc = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_00647b40,"Gravity");
    if (DAT_029208cc != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647b00,(float)DAT_008101bc * -10.0,
                           (float)DAT_008101bc * 20.0,*(float *)(DAT_02920970 + 200) * 0.5,"Gravity"
                          );
      FUN_00618e10(DAT_029208cc,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00647b20,0,(float)DAT_008101bc,
                           *(undefined4 *)(DAT_02920970 + 0xd0),"Bounce");
      FUN_00618e10(DAT_029208cc,uVar1);
      FUN_006279b0(param_1,DAT_029208cc);
      *(int *)(DAT_029208cc + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_029208cc + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

