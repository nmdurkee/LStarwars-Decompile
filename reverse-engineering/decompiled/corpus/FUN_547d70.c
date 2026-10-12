/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547d70; label: FUN_00547d70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547d70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (_DAT_00924ddc <= 0.0) {
    iVar1 = FUN_0054fa60();
    if (iVar1 < 0x400) {
      FUN_00681f40(param_1,param_2);
      iVar1 = FUN_0054fa60();
      _DAT_00924ddc = (float)iVar1 * 1.5259022e-05 + (float)iVar1 * 1.5259022e-05 + 3.0;
    }
  }
  return;
}

