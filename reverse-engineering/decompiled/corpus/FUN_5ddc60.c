/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5ddc60; label: FUN_005ddc60
 */

undefined4 FUN_005ddc60(int param_1)

{
  if ((param_1 != 0) && (-1 < *(int *)(param_1 + 0x20))) {
    return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x20) * 4);
  }
  return 0xffffffff;
}

