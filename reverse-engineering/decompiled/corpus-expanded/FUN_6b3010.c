/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b3010; label: FUN_006b3010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b3010(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x714);
    _free(param_1);
  }
  return;
}

