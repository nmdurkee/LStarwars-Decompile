/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff100; label: FUN_004ff100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff100(void)

{
  if (DAT_00921244 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_009209c4);
    DAT_00921244 = 1;
  }
  return;
}

