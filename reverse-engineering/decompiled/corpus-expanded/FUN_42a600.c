/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a600; label: FUN_0042a600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042a600(short *param_1)

{
  if ((DAT_0087b02c != 0) &&
     ((int)*(char *)(*param_1 * 0x130 + 0xa3 + DAT_00951b78) == (uint)*(byte *)(DAT_0087b02c + 0x7c)
     )) {
    return 0;
  }
  return 1;
}

