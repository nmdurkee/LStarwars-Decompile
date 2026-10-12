/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c5c80; label: FUN_006c5c80
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

