/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58dd60; label: FUN_0058dd60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058dd60(int param_1)

{
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffeffff;
  *(undefined4 *)(param_1 + 0xd3c) = 0;
  *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) & 0xffffffef;
  *(undefined1 *)(param_1 + 0xe33) = 0;
  return;
}

