/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428ea0; label: FUN_00428ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00428ea0(int param_1)

{
  if ((DAT_00876580 == 0) && (DAT_007f39e4 == 0)) {
    return *(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 0x17 & 1;
  }
  return 1;
}

