/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515270; label: FUN_00515270
 */

float10 FUN_00515270(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 0xd4) != 0)) {
    return (float10)*(float *)(param_3 + 0xd8);
  }
  return (float10)3.4028235e+38;
}

