/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x6331d0; label: FUN_006331d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

