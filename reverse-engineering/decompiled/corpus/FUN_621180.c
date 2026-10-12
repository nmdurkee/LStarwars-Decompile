/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x621180; label: FUN_00621180
 */

void FUN_00621180(undefined1 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_1[1];
  param_1[1] = uVar1;
  return;
}

