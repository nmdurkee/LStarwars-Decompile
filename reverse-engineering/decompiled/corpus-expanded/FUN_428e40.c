/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428e40; label: FUN_00428e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00428e40(int param_1)

{
  if (DAT_00876580 != 0) {
    return 1;
  }
  return *(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 0x17 & 1;
}

