/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x650c50; label: FUN_00650c50
 */

int FUN_00650c50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_02962024;
  if ((DAT_02962024 != 0x80) && (DAT_02962020 != 0x200)) {
    *(short *)(&DAT_02920d88 + DAT_02962024 * 8) = (short)DAT_02962020;
    *(undefined2 *)(&DAT_02920d8a + iVar2 * 8) = 1;
    iVar1 = DAT_02947b74;
    *(undefined2 *)(&DAT_02920d8c + iVar2 * 8) = 0;
    *(short *)(param_1 * 0x40 + 0x14 + iVar1) = (short)iVar2;
    *(short *)(&DAT_02921260 + DAT_02962020 * 2) = (short)param_1;
    DAT_02962020 = DAT_02962020 + 1;
    iVar2 = DAT_02962024;
    DAT_02962024 = DAT_02962024 + 1;
    return iVar2;
  }
  return -1;
}

