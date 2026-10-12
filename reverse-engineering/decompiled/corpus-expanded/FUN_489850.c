/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x489850; label: FUN_00489850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00489850(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00489770(param_1,param_2,param_3);
  if (iVar1 != 0) {
    FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),param_4,1);
    return 1;
  }
  return 0;
}

