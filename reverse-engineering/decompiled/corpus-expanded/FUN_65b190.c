/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65b190; label: FUN_0065b190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065b190(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00543cf0(*(undefined4 *)(param_2 + 0xc));
  if (iVar1 != 0) {
    FUN_00628d80();
    return;
  }
  FUN_00628d80();
  return;
}

