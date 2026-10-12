/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515580; label: FUN_00515580
 */

float10 FUN_00515580(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    return (float10)(*(float *)(*(int *)(param_3 + 0xe4) + 0x60) - *(float *)(param_5 + 0x14));
  }
  return (float10)3.4028235e+38;
}

