/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x699260; label: FUN_00699260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

