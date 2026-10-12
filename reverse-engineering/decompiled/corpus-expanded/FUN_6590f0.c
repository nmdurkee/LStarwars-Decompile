/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x6590f0; label: FUN_006590f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006590f0(void)

{
  if (DAT_029620cc != 0) {
    if (DAT_029620c8 != 0) {
      FUN_005e50e0(DAT_029620c8);
      DAT_029620c8 = 0;
    }
    if (_DAT_029620b0 != 0) {
      FUN_005e5630(_DAT_029620b0);
      _DAT_029620b0 = 0;
    }
    DAT_029620cc = 0;
  }
  return;
}

