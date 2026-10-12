/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x650570; label: FUN_00650570
 */

void FUN_00650570(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (-1 < param_1) {
    iVar1 = *(int *)(param_1 * 0x40 + 4 + DAT_02947b74) << 0x11;
    uVar2 = iVar1 >> 0x11;
    if ((uVar2 < 0x640) && (iVar1 = (int)(uVar2 + (iVar1 >> 0x1f & 0xfU)) >> 4, iVar1 < 100)) {
      *(ushort *)(&DAT_02921760 + iVar1 * 2) =
           *(ushort *)(&DAT_02921760 + iVar1 * 2) | (ushort)(1 << ((byte)uVar2 & 0xf));
    }
  }
  return;
}

