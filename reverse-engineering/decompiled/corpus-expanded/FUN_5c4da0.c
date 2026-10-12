/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4da0; label: FUN_005c4da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4da0(void)

{
  int in_ECX;
  
  FUN_00605ad0(*(undefined4 *)(in_ECX + 0xc));
  FUN_00605ad0(*(undefined4 *)(in_ECX + 8));
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}

