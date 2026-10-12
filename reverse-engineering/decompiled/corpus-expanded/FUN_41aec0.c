/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41aec0; label: FUN_0041aec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char FUN_0041aec0(int param_1)

{
  if ((*(char *)(param_1 + 0x7b5) == 'M') && (*(char *)(param_1 + 0x7b3) == '\0')) {
    return '\x02';
  }
  return (*(char *)(param_1 + 0x7b5) == 'R') + '\x01';
}

