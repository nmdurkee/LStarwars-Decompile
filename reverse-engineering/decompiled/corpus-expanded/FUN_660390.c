/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x660390; label: FUN_00660390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00660390(void)

{
  int iVar1;
  
  iVar1 = 1;
  if (1 < DAT_02962098) {
    do {
      *(undefined4 *)(DAT_0296209c + iVar1 * 4) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_02962098);
  }
  DAT_02962a24 = 1;
  return;
}

