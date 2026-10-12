/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515130; label: FUN_00515130
 */

float10 FUN_00515130(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) || (param_5 = *(int *)(param_2 + 0xa0), param_5 != 0)) &&
     ((*(byte *)(param_5 + 0x2a) & 2) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

