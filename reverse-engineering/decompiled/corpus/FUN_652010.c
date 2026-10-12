/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x652010; label: FUN_00652010
 */

void FUN_00652010(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = true;
  iVar3 = -1;
  iVar2 = FUN_004f7fb0(param_1);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    if (bVar1) {
      if (iVar2 == -1) {
        return;
      }
      iVar3 = FUN_00650c50(iVar2);
      bVar1 = false;
    }
    else {
      iVar2 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
      if ((iVar2 != -1) && (DAT_02962020 != 0x200)) {
        *(short *)(&DAT_02921260 + DAT_02962020 * 2) = (short)iVar2;
        DAT_02962020 = DAT_02962020 + 1;
        *(short *)(&DAT_02920d8a + iVar3 * 8) = *(short *)(&DAT_02920d8a + iVar3 * 8) + 1;
        *(undefined2 *)(&DAT_02920d8c + iVar3 * 8) = 0;
      }
    }
    iVar2 = FUN_004f7fb0(param_1);
  } while( true );
}

