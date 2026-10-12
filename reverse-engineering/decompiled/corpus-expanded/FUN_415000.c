/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x415000; label: FUN_00415000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00415000(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c8);
  if (iVar1 != 0) {
    FUN_00514640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1 + 0x2c8,param_1 + 0x2c8,0,0,0,0,
                 iVar1,*(undefined4 *)(iVar1 + 0x38));
    *(undefined4 *)(param_1 + 0x32c) = 0;
  }
  return;
}

