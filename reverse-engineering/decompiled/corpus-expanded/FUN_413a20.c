/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x413a20; label: FUN_00413a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00413a20(int param_1)

{
  int iVar1;
  
  FUN_00412580(param_1);
  FUN_00411980(param_1);
  iVar1 = 0;
  do {
    *(undefined4 *)(iVar1 + 0x38d0 + *(int *)(param_1 + 0x511c)) = 0;
    iVar1 = iVar1 + 0x530;
  } while (iVar1 < 0x53000);
  if (*(int *)(param_1 + 0x128) == DAT_0087b0f8) {
    FUN_0040f920(param_1,*(int *)(param_1 + 0x511c) + 0x34d0,0x100);
  }
  FUN_004100b0();
  return;
}

