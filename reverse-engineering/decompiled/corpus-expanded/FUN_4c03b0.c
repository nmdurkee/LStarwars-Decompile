/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c03b0; label: FUN_004c03b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c03b0(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x3c);
    *pbVar1 = *pbVar1 ^ (param_2 != 0 ^ *(byte *)(*param_1 + 0x3c)) & 1;
  }
  return;
}

