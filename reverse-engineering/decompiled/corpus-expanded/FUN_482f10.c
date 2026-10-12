/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x482f10; label: FUN_00482f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00482f10(int param_1)

{
  if (*(char *)(*(char *)(param_1 + 0xb8) + 0xf0 + param_1) != '\0') {
    DAT_0087a32c = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x14);
    DAT_0087a1e0 = (int)*(char *)(param_1 + 0xb8);
  }
  return;
}

