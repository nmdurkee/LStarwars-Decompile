/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647640; label: FUN_00647640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647640(int param_1)

{
  undefined4 uVar1;
  
  DAT_0291f784 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00647620,"Super Scale");
  if (DAT_0291f784 != 0) {
    uVar1 = FUN_00625240(0,&DAT_008109d8,0,FUN_00647600,1,99,DAT_008101bc,"Super Scale");
    FUN_00618e10(DAT_0291f784,uVar1);
    FUN_006279b0(param_1,DAT_0291f784);
    *(int *)(DAT_0291f784 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0291f784 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

