/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e27f0; label: FUN_006e27f0
 */

bool FUN_006e27f0(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0x654) & 0x20) != 0;
}

