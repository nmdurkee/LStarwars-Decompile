/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42a920; label: FUN_0042a920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0042a920(int param_1)

{
  if (*(short *)(param_1 + 0xe6) == 0xd0) {
    return *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd10;
  }
  return 0;
}

