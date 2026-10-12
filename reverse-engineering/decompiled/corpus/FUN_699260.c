/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x699260; label: FUN_00699260
 */

undefined1 FUN_00699260(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int in_ECX;
  int *piVar2;
  undefined1 uVar3;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 0x70);
  uVar3 = 0;
  EnterCriticalSection(lpCriticalSection);
  iVar1 = 0;
  if (*(int *)(in_ECX + 0x1b8) != 0) {
    piVar2 = (int *)(in_ECX + 0xb8);
    while (*piVar2 != param_1) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (iVar1 == *(int *)(in_ECX + 0x1b8)) {
        LeaveCriticalSection(lpCriticalSection);
        return 0;
      }
    }
    uVar3 = 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar3;
}

