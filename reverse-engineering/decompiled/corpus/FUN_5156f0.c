/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x5156f0; label: FUN_005156f0
 */

float10 FUN_005156f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && ((*(uint *)(param_3 + 0x1e8) & 0x400000) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

