/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x554d40; label: FUN_00554d40
 */

char FUN_00554d40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_005a0f10(*(undefined4 *)(param_1 + 0x68));
  if (iVar1 != 0) {
    return '\0';
  }
  return (*(int *)(*(int *)(param_1 + 0x68) + 0xc) == 2) + '\x01';
}

