/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x650e90; label: FUN_00650e90
 */

undefined4 FUN_00650e90(int param_1)

{
  if (-1 < param_1) {
    return *(undefined4 *)(param_1 * 0x40 + DAT_02947b74);
  }
  return 0;
}

