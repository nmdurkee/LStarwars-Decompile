/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428ef0; label: FUN_00428ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00428ef0(int param_1)

{
  if ((*(short *)(param_1 + 0x1064) == DAT_007f1968) &&
     (((*(byte *)(param_1 + 0xe22) & 1) == 0 || (*(char *)(param_1 + 0xe33) == '\x02')))) {
    return 1;
  }
  return 0;
}

