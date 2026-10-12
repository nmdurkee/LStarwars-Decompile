/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6331d0; label: FUN_006331d0
 */

void FUN_006331d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_00632f50();
      return;
    }
    FUN_00632b80(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}

