/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x490b70; label: FUN_00490b70
 */

byte FUN_00490b70(int param_1)

{
  return *(byte *)(param_1 + 0x94) >> 1 & 1;
}

