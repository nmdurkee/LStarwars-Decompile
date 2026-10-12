/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x5478a0; label: FUN_005478a0
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

