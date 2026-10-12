/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a3f0; label: FUN_0048a3f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048a3f0(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_EDI + 0x2aec)) {
    do {
      FUN_0048a250();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_EDI + 0x2aec));
  }
  return;
}

