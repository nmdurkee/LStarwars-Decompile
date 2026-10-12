/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60e880; label: FUN_0060e880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e880(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2170) = *param_1;
  *(undefined4 *)(in_ECX + 0x2174) = 1;
  return;
}

