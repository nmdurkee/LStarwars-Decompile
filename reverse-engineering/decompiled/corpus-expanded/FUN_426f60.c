/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x426f60; label: FUN_00426f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426f60(int param_1)

{
  FUN_00404e30(param_1);
  FUN_00426de0(param_1 + 0xc,0);
  *(undefined1 *)(param_1 + 0x28) = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x20) = _DAT_007f38fc;
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return;
}

