/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fac50; label: FUN_005fac50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005fac50(ushort *param_1,ushort *param_2)

{
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (uint)(*param_1 != *param_2);
}

