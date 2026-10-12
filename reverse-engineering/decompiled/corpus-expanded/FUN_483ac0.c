/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x483ac0; label: FUN_00483ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00483ac0(int param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)(*(byte *)(param_1 + 0xb7) + 200 + param_1) = param_2;
  *(undefined1 *)(*(byte *)(param_1 + 0xb7) + 0xf0 + param_1) = param_3;
  *(char *)(param_1 + 0xb7) = *(char *)(param_1 + 0xb7) + '\x01';
  return;
}

