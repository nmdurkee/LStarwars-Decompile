/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afaa0; label: FUN_005afaa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005afaa0(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x23);
    *pbVar1 = *pbVar1 ^ (param_2 != 0 ^ *(byte *)(*param_1 + 0x23)) & 1;
  }
  return;
}

