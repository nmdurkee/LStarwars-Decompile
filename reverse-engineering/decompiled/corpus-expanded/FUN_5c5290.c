/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c5290; label: FUN_005c5290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c5290(void)

{
  char *in_ECX;
  
  if ((*in_ECX != '\0') && (in_ECX[1] != '\0')) {
    return 1;
  }
  return 0;
}

