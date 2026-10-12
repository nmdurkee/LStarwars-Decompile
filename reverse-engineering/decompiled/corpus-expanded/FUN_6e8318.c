/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e8318; label: FUN_006e8318
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e8318(uint param_1)

{
  if ((0x82958f < param_1) && (param_1 < 0x8297f1)) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffff7fff;
    FUN_006f179a(((int)(param_1 - 0x829590) >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

