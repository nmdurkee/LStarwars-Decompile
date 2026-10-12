/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62a980; label: FUN_0062a980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062a980(int *param_1)

{
  if (param_1 != (int *)0x0) {
    _memset((void *)param_1[1],0,*param_1 << 6);
  }
  return;
}

