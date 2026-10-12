/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x5478a0; label: FUN_005478a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005478a0(undefined4 param_1,undefined4 *param_2,int param_3)

{
  if (param_3 != 0) {
    if ((param_3 == 1) || (param_3 == 3)) {
      _DAT_02962b5c = *param_2;
      _DAT_02962b60 = param_2[1];
      _DAT_02962b64 = param_2[2];
      FUN_00681e90(param_1,&DAT_02962b5c);
    }
    if ((param_3 == 2) || (param_3 == 3)) {
      _DAT_02962b68 = *param_2;
      _DAT_02962b6c = param_2[1];
      _DAT_02962b70 = param_2[2];
      FUN_00681e90(param_1,&DAT_02962b68);
    }
    return;
  }
  FUN_00681e90(param_1,param_2);
  return;
}

