/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65f720; label: FUN_0065f720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065f720(int param_1)

{
  undefined4 uVar1;
  
  DAT_029629b8 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_0065f700,"Super Scale");
  if (DAT_029629b8 != 0) {
    uVar1 = FUN_00625240(0,&DAT_008109d8,0,FUN_0065f6e0,1,99,DAT_00810a94,"Super Scale");
    FUN_00618e10(DAT_029629b8,uVar1);
    FUN_006279b0(param_1,DAT_029629b8);
    *(int *)(DAT_029629b8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029629b8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

