/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff0a0; label: FUN_004ff0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004ff0a0(void)

{
  DWORD DVar1;
  
  DVar1 = GetCurrentThreadId();
  return DVar1 == DAT_00921238;
}

