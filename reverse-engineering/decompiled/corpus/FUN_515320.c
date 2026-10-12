/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515320; label: FUN_00515320
 */

float10 FUN_00515320(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     (*(float *)(*(int *)(param_3 + 0xe4) + 0x60) <
      *(float *)(*(int *)(param_3 + 0xd0) + 0x60) - 0.1)) {
    return (float10)1;
  }
  return (float10)0;
}

