/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x6e9d42; label: FUN_006e9d42
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

char * FUN_006e9d42(void)

{
  char *pcVar1;
  int in_ECX;
  
  pcVar1 = *(char **)(in_ECX + 4);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "Unknown exception";
  }
  return pcVar1;
}

