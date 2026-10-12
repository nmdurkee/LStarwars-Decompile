/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c20e0; label: FUN_005c20e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c20e0(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
  return;
}

