/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42a9b0; label: FUN_0042a9b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042a9b0(int param_1)

{
  if ((((*(short *)(param_1 + 0x1064) == DAT_007f19a0) && (DAT_00804c08 != -1)) &&
      (*(short *)(param_1 + 0x7aa) == DAT_00804c08)) &&
     (((*(byte *)(param_1 + 0xe22) & 1) == 0 || (*(char *)(param_1 + 0xe33) == '\x02')))) {
    FUN_0062e650(param_1 + 8,0xffffffff);
  }
  return;
}

