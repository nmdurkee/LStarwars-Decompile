/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x699200; label: FUN_00699200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00699200(undefined4 *param_1)

{
  int in_ECX;
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    uVar1 = *(undefined4 *)(in_ECX + 0xb8 + *(int *)(in_ECX + 0x1bc) * 4);
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *(undefined4 *)(in_ECX + 0x138 + *(int *)(in_ECX + 0x1bc) * 4);
    }
    *(int *)(in_ECX + 0x1b8) = *(int *)(in_ECX + 0x1b8) + -1;
    *(uint *)(in_ECX + 0x1bc) = *(int *)(in_ECX + 0x1bc) + 1U & 0x1f;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
  return uVar1;
}

