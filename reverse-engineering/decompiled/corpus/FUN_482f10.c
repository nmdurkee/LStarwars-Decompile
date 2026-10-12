/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x482f10; label: FUN_00482f10
 */

void FUN_00482f10(int param_1)

{
  if (*(char *)(*(char *)(param_1 + 0xb8) + 0xf0 + param_1) != '\0') {
    DAT_0087a32c = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x14);
    DAT_0087a1e0 = (int)*(char *)(param_1 + 0xb8);
  }
  return;
}

