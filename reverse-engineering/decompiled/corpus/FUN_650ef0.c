/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x650ef0; label: FUN_00650ef0
 */

uint FUN_00650ef0(int param_1)

{
  if (param_1 != -1) {
    return *(uint *)(param_1 * 0x40 + 4 + DAT_02947b74) >> 0xf & 1;
  }
  return 0xffffffff;
}

