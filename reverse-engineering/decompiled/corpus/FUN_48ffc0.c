/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x48ffc0; label: FUN_0048ffc0
 */

void FUN_0048ffc0(int param_1)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x7b5) == 'J') && (iVar1 = *(int *)(param_1 + 0x798), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x94) & 2) == 0)) {
    *(ushort *)(iVar1 + 0x94) = *(ushort *)(iVar1 + 0x94) & 0xfffe;
  }
  return;
}

