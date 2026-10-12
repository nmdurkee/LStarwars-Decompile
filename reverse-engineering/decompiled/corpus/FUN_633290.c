/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x633290; label: FUN_00633290
 */

void FUN_00633290(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_00633000();
    return;
  }
  FUN_00632a60();
  return;
}

