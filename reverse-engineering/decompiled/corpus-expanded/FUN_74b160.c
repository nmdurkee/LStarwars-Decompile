/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b160; label: FUN_0074b160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074b160(undefined1 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = 5;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = param_1;
  return;
}

