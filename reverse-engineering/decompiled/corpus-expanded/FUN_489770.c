/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x489770; label: FUN_00489770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00489770(undefined4 param_1,int param_2,float param_3)

{
  int iVar1;
  
  if ((&DAT_0087aa20)[param_2] == '\0') {
    iVar1 = FUN_0058b870(param_1);
    if (iVar1 != 0) {
      if (param_3 <= 0.0) goto LAB_004897cd;
      (&DAT_0087aa20)[param_2] = 1;
    }
  }
  else if ((&DAT_0087aa20)[param_2] == '\x01') {
    DAT_0087a9cc = DAT_0087a9cc + _DAT_00925018;
    if (param_3 < DAT_0087a9cc == (param_3 == DAT_0087a9cc)) {
      return 0;
    }
LAB_004897cd:
    (&DAT_0087aa20)[param_2] = 2;
    return 1;
  }
  return 0;
}

