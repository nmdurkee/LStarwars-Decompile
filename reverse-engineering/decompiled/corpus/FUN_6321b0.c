/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6321b0; label: FUN_006321b0
 */

void FUN_006321b0(int param_1)

{
  if (param_1 != 0) {
    (**(code **)(**(int **)(param_1 + 4) + 0xac))
              (*(int **)(param_1 + 4),0,0,1,0xff000000,0x3f800000,0);
    (**(code **)(**(int **)(param_1 + 4) + 0xa4))(*(int **)(param_1 + 4));
  }
  return;
}

