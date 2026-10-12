/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521200; label: FUN_00521200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00521200(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  
  if (*(int *)(DAT_009238e4 + 0x383c8) != 0) {
    if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
      pbVar1 = (byte *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x33);
      *pbVar1 = *pbVar1 | 1;
      return;
    }
    pbVar1 = (byte *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x33);
    *pbVar1 = *pbVar1 & 0xfe;
  }
  return;
}

