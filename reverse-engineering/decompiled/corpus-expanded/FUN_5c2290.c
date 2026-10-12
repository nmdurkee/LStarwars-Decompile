/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2290; label: FUN_005c2290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007642a4;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  return;
}

