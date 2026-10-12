/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x633220; label: FUN_00633220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633220(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_006324e0(param_2,param_3,param_4,param_5,*(undefined4 *)(param_1 + 0x14),
                   *(undefined4 *)(param_1 + 0x18));
      return;
    }
    FUN_00632db0(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

