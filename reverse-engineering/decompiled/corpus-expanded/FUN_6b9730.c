/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9730; label: FUN_006b9730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9730(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 0x28) {
    *(undefined1 *)(param_1 + 0xf0 + in_ECX) = 1;
    *(undefined4 *)(in_ECX + 0x118 + param_1 * 4) = 0;
  }
  return;
}

