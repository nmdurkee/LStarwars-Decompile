/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f500; label: FUN_0055f500
 */

undefined4 FUN_0055f500(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_0093d858;
  if (param_1 == &DAT_0093d858) {
    puVar1 = &DAT_00942a04;
  }
  if (*(int *)(puVar1 + 0x110) != 0) {
    return *(undefined4 *)(puVar1 + 0x11c);
  }
  return 0xffffffff;
}

