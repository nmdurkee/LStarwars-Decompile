/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402a80; label: FUN_00402a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00402a80(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x62);
    *pbVar1 = *pbVar1 ^ (param_2 != 0 ^ *(byte *)(*param_1 + 0x62)) & 1;
  }
  return;
}

