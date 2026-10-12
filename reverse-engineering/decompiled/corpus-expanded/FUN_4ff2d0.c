/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff2d0; label: FUN_004ff2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004ff2d0(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_008007a0)[iVar1] == -1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return -1;
}

