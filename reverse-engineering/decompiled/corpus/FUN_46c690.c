/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c690; label: FUN_0046c690
 */

undefined1 FUN_0046c690(void)

{
  int iVar1;
  
  iVar1 = FUN_0054fa60();
  return (&DAT_007f9028)[(int)(iVar1 + (iVar1 >> 0x1f & 0x3fffU)) >> 0xe];
}

