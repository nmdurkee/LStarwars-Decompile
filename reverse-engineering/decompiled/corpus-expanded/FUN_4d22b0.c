/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d22b0; label: FUN_004d22b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

