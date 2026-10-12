/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x427880; label: FUN_00427880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00427880(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
    iVar1 = 1;
  }
  if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

