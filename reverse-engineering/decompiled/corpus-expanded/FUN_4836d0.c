/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x4836d0; label: FUN_004836d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004836d0(int param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined1 *)(param_1 + 0x12) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
  }
  return;
}

