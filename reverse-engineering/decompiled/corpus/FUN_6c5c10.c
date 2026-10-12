/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c5c10; label: FUN_006c5c10
 */

undefined4 * FUN_006c5c10(undefined4 *param_1)

{
  int iVar1;
  
  while( true ) {
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = FUN_0061f030();
    if (param_1[2] == iVar1) break;
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}

