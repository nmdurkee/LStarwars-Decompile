/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428ff0; label: FUN_00428ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00428ff0(int param_1)

{
  if ((*(int *)(param_1 + 0xcbc) != 0) &&
     ((*(ushort *)(*(int *)(param_1 + 0xcbc) + 0xc) & 0x100) != 0)) {
    return 1;
  }
  return 0;
}

