/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e82ea; label: FUN_006e82ea
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e82ea(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    __lock(param_1 + 0x10);
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x8000;
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}

