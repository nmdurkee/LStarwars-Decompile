/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e82ae; label: FUN_006e82ae
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e82ae(uint param_1)

{
  if ((0x82958f < param_1) && (param_1 < 0x8297f1)) {
    __lock(((int)(param_1 - 0x829590) >> 5) + 0x10);
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x8000;
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

