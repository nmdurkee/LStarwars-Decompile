/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429bc0; label: FUN_00429bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00429bc0(int param_1)

{
  if (((*(short *)(param_1 + 0x1064) == DAT_007f1914) && (*(char *)(param_1 + 0x7b5) == '\x17')) &&
     (*(short *)(param_1 + 0x7aa) == 0x41)) {
    *(float *)(param_1 + 0x1dc) = *(float *)(param_1 + 0x1dc) + *(float *)(param_1 + 0x1dc);
  }
  return;
}

