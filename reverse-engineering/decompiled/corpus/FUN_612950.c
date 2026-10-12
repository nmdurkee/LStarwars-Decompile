/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612950; label: FUN_00612950
 */

bool FUN_00612950(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd838);
  do {
    if (*piVar2 == param_1) {
      return *(int *)(in_ECX + 0xd844 + iVar1 * 0x14) == 3;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 5;
  } while (iVar1 < 8);
  return false;
}

