/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504db0; label: FUN_00504db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00504db0(int param_1)

{
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 1;
  return;
}

