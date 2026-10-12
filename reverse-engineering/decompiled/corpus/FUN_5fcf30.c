/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcf30; label: FUN_005fcf30
 */

void FUN_005fcf30(int param_1)

{
  uint *puVar1;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar1 = DAT_009736e0;
  *(undefined4 *)*DAT_009736e0 = *(undefined4 *)(param_1 + 0x194);
  *puVar1 = *puVar1 + 4;
  return;
}

