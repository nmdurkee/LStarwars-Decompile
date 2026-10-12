/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x483a90; label: FUN_00483a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00483a90(int param_1,undefined2 param_2)

{
  if (DAT_0087a1d4 < 0x10) {
    *(undefined2 *)(param_1 + 300 + DAT_0087a1d4 * 2) = param_2;
    DAT_0087a1d4 = DAT_0087a1d4 + 1;
  }
  FUN_0055c8a0();
  return 1;
}

