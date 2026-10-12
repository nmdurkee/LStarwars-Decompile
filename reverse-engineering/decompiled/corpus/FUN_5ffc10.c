/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x5ffc10; label: FUN_005ffc10
 */

void FUN_005ffc10(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0280d3cc;
  do {
    FUN_006e5b70(puVar1);
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)&DAT_0280d3dc);
  return;
}

