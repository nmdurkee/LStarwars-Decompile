/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x427c70; label: FUN_00427c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00427c70(int param_1)

{
  undefined2 uVar1;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0a0) &&
     ((DAT_0087b014 == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x24;
    uVar1 = FUN_0062f1a0(param_1 + 8);
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined2 *)(param_1 + 0x7aa) = uVar1;
    *(undefined4 *)(param_1 + 0x784) = 0x3f000000;
  }
  return;
}

