/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748770; label: FUN_00748770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748770(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x948) = *(undefined4 *)(in_ECX + 0x950);
  *(undefined4 *)(in_ECX + 0x4b0) = 0;
  return;
}

