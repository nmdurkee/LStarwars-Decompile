/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x699710; label: FUN_00699710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

