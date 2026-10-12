/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e5bc0; label: FUN_005e5bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005e5bc0(int param_1)

{
  int in_ECX;
  
  return (int)*(char *)((param_1 >> 3) + 0x200 + in_ECX) >> ((byte)param_1 & 7) & 1;
}

