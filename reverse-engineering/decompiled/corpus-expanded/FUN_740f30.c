/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x740f30; label: FUN_00740f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00740f30(int param_1,int param_2)

{
  undefined1 *in_ECX;
  
  *(int *)(in_ECX + 4) = param_1;
  *(int *)(in_ECX + 0xc) = param_1;
  *in_ECX = 0;
  *(int *)(in_ECX + 8) = param_1 + param_2;
  return;
}

