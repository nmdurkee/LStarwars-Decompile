/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4fea50; label: FUN_004fea50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 * FUN_004fea50(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_1) {
    do {
      if (DAT_00921228 <= iVar2) break;
      pcVar1 = &DAT_009209e8 + iVar2;
      iVar2 = iVar2 + 1;
      if (*pcVar1 == '\0') {
        iVar3 = iVar3 + 1;
      }
    } while (iVar3 < param_1);
  }
  return &DAT_009209e8 + iVar2;
}

