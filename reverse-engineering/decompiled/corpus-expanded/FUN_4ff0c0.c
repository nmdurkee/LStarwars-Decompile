/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff0c0; label: FUN_004ff0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff0c0(DWORD param_1)

{
  int iVar1;
  
  if (DAT_0091f1b4 != 0) {
    if ((DAT_00921230 == 0) && (iVar1 = FUN_00547580(DAT_0091f1b4,0), iVar1 == 0)) {
      return;
    }
    Sleep(param_1);
  }
  return;
}

