/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e58d0; label: FUN_005e58d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005e58d0(void)

{
  int *in_ECX;
  
  return *(undefined4 *)(in_ECX[1] + *in_ECX * 0x28);
}

