/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58ecf0; label: FUN_0058ecf0
 */

undefined4 FUN_0058ecf0(int param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x6d) == '\x02')) {
    return 1;
  }
  return 0;
}

