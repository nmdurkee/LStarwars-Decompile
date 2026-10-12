/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c21c0; label: FUN_005c21c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c21c0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  *(undefined1 *)(in_ECX + 2) = param_3;
  *(undefined1 *)((int)in_ECX + 9) = param_4;
  return;
}

