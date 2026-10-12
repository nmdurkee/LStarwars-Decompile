/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x547d70; label: FUN_00547d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

