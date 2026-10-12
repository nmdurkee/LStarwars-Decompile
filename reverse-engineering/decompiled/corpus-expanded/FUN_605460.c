/* Ghidra pseudocode, not original source.
 * ev_c781f6f2f7d78097ae9ff869f9175a8231755f2e9224784a2b208dfae7521271
 * Entry: 0x605460; label: FUN_00605460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00605460(int param_1)

{
  int in_ECX;
  
  return (int)*(char *)((param_1 >> 3) + 0x300 + in_ECX) >> ((byte)param_1 & 7) & 1;
}

