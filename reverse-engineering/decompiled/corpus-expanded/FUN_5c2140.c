/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2140; label: FUN_005c2140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2140(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + param_1 * 0x28) = param_2;
  return;
}

