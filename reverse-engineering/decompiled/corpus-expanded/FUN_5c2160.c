/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2160; label: FUN_005c2160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c2160(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + param_1 * 0x28);
}

