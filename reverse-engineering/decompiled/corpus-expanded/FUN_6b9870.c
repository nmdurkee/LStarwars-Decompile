/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9870; label: FUN_006b9870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9870(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0xc) = 0;
  }
  if (*(int *)(in_ECX + 0x14) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0xc) = 0;
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0xc) = 0;
  }
  return;
}

