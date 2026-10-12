/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x427ad0; label: FUN_00427ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00427ad0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x7b5) == '#') {
    iVar1 = FUN_006e6b90();
    return (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
  }
  if (*(char *)(param_1 + 0x7b5) == '$') {
    iVar1 = FUN_006e6b90();
    return (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
  }
  return (float10)1;
}

