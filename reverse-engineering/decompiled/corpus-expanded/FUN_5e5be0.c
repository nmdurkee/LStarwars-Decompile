/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e5be0; label: FUN_005e5be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5be0(int param_1,char param_2)

{
  byte *pbVar1;
  int in_ECX;
  byte bVar2;
  
  pbVar1 = (byte *)((param_1 >> 3) + 0x200 + in_ECX);
  bVar2 = '\x01' << ((byte)param_1 & 7);
  if (param_2 != '\0') {
    *pbVar1 = *pbVar1 | bVar2;
    return;
  }
  *pbVar1 = *pbVar1 & ~bVar2;
  return;
}

