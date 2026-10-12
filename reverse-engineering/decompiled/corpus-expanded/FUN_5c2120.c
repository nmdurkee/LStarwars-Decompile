/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2120; label: FUN_005c2120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c2120(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x24 + param_1 * 0x28);
  *piVar1 = *piVar1 + -1;
  return in_ECX + param_1 * 0x28;
}

