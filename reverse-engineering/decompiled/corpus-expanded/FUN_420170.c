/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x420170; label: FUN_00420170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00420170(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x5c + param_1 * 4);
}

