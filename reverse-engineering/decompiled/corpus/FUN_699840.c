/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x699840; label: FUN_00699840
 */

void FUN_00699840(void)

{
  int *piVar1;
  int in_ECX;
  
  if ((in_ECX != 0) && (*(int *)(in_ECX + 0x3f4) != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
    if ((*(int *)(in_ECX + 8) == 2) && (piVar1 = *(int **)(in_ECX + 0x54), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x30))(piVar1,0,0,1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
    *(undefined4 *)(in_ECX + 0x3f4) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x88));
  }
  return;
}

