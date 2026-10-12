/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5c80; label: FUN_006c5c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c5c80(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 8), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x3c) != 0) {
      iVar1 = FUN_006bdfe0(*(int *)(iVar1 + 0x3c));
    }
    FUN_006271a0(iVar1);
    return;
  }
  iVar1 = DAT_02973a7c;
  if (DAT_02973a7c == 0) {
    iVar1 = DAT_02973a80;
  }
  FUN_006271a0(iVar1);
  return;
}

