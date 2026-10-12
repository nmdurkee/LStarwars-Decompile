/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e5870; label: FUN_005e5870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005e5870(void)

{
  int *in_ECX;
  
  return *(undefined4 *)(in_ECX[1] + *in_ECX * 0x28);
}

