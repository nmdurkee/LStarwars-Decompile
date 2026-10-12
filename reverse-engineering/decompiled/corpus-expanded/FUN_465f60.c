/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x465f60; label: FUN_00465f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465f60(int *param_1,int param_2)

{
  ushort *puVar1;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (ushort *)(*param_1 + 0x2a);
    *puVar1 = *puVar1 ^ (param_2 != 0 ^ *(byte *)(*param_1 + 0x2a)) & 1;
  }
  return;
}

