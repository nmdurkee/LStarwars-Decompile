/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d22b0; label: FUN_004d22b0
 */

undefined * FUN_004d22b0(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  pbVar1 = &DAT_00881261;
  do {
    if ((*pbVar1 & 1) == 0) {
      (&DAT_00881261)[iVar2 * 0x88] = (&DAT_00881261)[iVar2 * 0x88] | 1;
      return &DAT_00881260 + iVar2 * 0x88;
    }
    pbVar1 = pbVar1 + 0x88;
    iVar2 = iVar2 + 1;
  } while ((int)pbVar1 < 0x881ae1);
  return (undefined *)0x0;
}

