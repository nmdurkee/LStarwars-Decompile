/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff380; label: FUN_004ff380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004ff380(int param_1)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle((HANDLE)(&DAT_008007a0)[param_1]);
  (&DAT_008007a0)[param_1] = 0xffffffff;
  return BVar1 == 0;
}

