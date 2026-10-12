/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b94d0; label: FUN_006b94d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b94d0(undefined4 *param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) == 1) {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0xc47a0000;
    *(undefined4 *)(in_ECX + 0x58) = 0;
  }
  if (*(int *)(in_ECX + 100) == 2) {
    *(undefined4 *)(in_ECX + 0x50) = *param_1;
    *(undefined4 *)(in_ECX + 0x54) = param_1[1];
    *(undefined4 *)(in_ECX + 0x58) = param_1[2];
    *(undefined4 *)(in_ECX + 0x5c) = param_1[3];
  }
  return;
}

