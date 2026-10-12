/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x749360; label: FUN_00749360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00749360(void)

{
  int *in_ECX;
  
  if ((in_ECX[3] == 0) && ((*(uint *)(*in_ECX + 0x1b8) & 0x1000) == 0)) {
    return 1;
  }
  return 0;
}

