/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2400; label: FUN_005c2400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2400(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x120) = param_2;
  *(undefined4 *)(in_ECX + 0x11c) = param_1;
  *(undefined4 *)(in_ECX + 0x124) = param_3;
  return;
}

