/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60e860; label: FUN_0060e860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0060e860(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2174) != 0) {
    return in_ECX + 0x2170;
  }
  return 0;
}

