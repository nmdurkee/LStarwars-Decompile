/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7330; label: FUN_006b7330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006b7330(float *param_1,float *param_2)

{
  if (*param_2 < *param_1) {
    return (*param_1 < *param_2) - 1;
  }
  return (uint)(*param_1 < *param_2);
}

