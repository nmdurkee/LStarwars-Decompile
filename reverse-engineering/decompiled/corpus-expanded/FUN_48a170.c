/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a170; label: FUN_0048a170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048a170(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  if (param_1 != 0) {
    pcVar1 = (char *)(param_1 + 0x2d68);
    iVar2 = 0xc;
    do {
      if (*pcVar1 != '\0') {
        FUN_005a8280(pcVar1,0);
      }
      pcVar1 = pcVar1 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

