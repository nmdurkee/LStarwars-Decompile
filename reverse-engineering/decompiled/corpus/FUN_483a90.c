/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483a90; label: FUN_00483a90
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

