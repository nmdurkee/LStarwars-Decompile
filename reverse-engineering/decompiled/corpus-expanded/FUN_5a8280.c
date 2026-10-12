/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8280; label: FUN_005a8280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8280(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  iVar1 = FUN_00658490(param_1,*(undefined1 *)(iVar1 + 0x2a98));
  if (iVar1 != -1) {
    if (param_2 != 0) {
      FUN_00655340();
      return;
    }
    FUN_00655320(iVar1);
  }
  return;
}

