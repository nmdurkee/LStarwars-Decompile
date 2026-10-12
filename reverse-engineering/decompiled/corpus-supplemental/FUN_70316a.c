/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x70316a; label: FUN_0070316a
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

byte FUN_0070316a(void)

{
  int in_ECX;
  
  return (*(int *)(in_ECX + 8) != 2) - 1U & 0x20;
}

