/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x6997f0; label: FUN_006997f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006997f0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (in_ECX != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x88));
    EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
    if ((*(int *)(in_ECX + 8) == 2) && (piVar1 = *(int **)(in_ECX + 0x54), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
    *(undefined4 *)(in_ECX + 0x3f4) = 1;
  }
  return;
}

