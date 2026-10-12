/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x650e40; label: FUN_00650e40
 */

int FUN_00650e40(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = FUN_004f8b80(param_1,*(undefined4 *)(iVar2 + DAT_02947b74),param_2);
    if (iVar1 == 0) {
      return iVar3;
    }
    iVar2 = iVar2 + 0x40;
    iVar3 = iVar3 + 1;
  } while (iVar2 < 0x19000);
  FUN_0064fdb0(param_1);
  return -1;
}

