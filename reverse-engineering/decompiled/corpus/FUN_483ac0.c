/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483ac0; label: FUN_00483ac0
 */

void FUN_00483ac0(int param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)(*(byte *)(param_1 + 0xb7) + 200 + param_1) = param_2;
  *(undefined1 *)(*(byte *)(param_1 + 0xb7) + 0xf0 + param_1) = param_3;
  *(char *)(param_1 + 0xb7) = *(char *)(param_1 + 0xb7) + '\x01';
  return;
}

