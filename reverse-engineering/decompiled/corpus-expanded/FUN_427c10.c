/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x427c10; label: FUN_00427c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00427c10(int param_1)

{
  uint uVar1;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0a0) &&
     ((DAT_0087b014 == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x23;
    uVar1 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined4 *)(param_1 + 0x784) = 0x3f000000;
    *(ushort *)(param_1 + 0x7aa) = ~(ushort)(uVar1 >> 0xb) & 4 | 1;
  }
  return;
}

