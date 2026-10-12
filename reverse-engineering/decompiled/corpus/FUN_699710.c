/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x699710; label: FUN_00699710
 */

undefined4 FUN_00699710(undefined4 param_1)

{
  int in_ECX;
  
  if (in_ECX == 0) {
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x54) + 0x3c))
              (*(undefined4 *)(in_ECX + 0x54),*(undefined4 *)(in_ECX + 0x10));
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x10);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
  return 1;
}

