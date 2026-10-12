/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x66ffa0; label: FUN_0066ffa0
 */

undefined2
FUN_0066ffa0(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  if ((param_2 - param_4) * (param_3 - param_5) + (param_1 - param_3) * (param_6 - param_4) < 0.0) {
    return 0;
  }
  return 1;
}

