/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a5d0; label: FUN_0042a5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042a5d0(void)

{
  if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1b8) && (PTR_DAT_008021b4[1] != '\0')) &&
     (PTR_DAT_008021b4[1] != '\x03')) {
    return 0;
  }
  return 1;
}

