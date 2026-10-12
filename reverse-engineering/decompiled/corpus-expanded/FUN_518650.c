/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x518650; label: FUN_00518650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00518650(void *param_1)

{
  if ((*(byte *)((int)param_1 + 0x49) & 1) != 0) {
    _memset(param_1,0,0x58);
  }
  return;
}

