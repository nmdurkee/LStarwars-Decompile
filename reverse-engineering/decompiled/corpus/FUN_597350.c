/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x597350; label: FUN_00597350
 */

void FUN_00597350(int param_1)

{
  if ((param_1 != 0) && (*(void **)(param_1 + 0x10ac) != (void *)0x0)) {
    _memset(*(void **)(param_1 + 0x10ac),0,0x110);
    *(undefined4 *)(param_1 + 0x10ac) = 0;
  }
  return;
}

