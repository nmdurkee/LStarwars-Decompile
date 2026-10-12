/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5aae60; label: FUN_005aae60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_005aae60(int *param_1,uint param_2)

{
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (param_2 < 8)) {
    _sprintf(&DAT_0095df50,"%d",(int)*(char *)(*param_1 + 0x2c + param_2));
    return &DAT_0095df50;
  }
  return (undefined *)0x0;
}

