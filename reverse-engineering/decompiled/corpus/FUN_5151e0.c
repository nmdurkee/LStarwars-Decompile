/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x5151e0; label: FUN_005151e0
 */

float10 FUN_005151e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((*(uint *)(param_3 + 0x1e8) & 0x800) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

