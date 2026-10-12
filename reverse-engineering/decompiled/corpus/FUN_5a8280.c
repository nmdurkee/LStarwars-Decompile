/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8280; label: FUN_005a8280
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

