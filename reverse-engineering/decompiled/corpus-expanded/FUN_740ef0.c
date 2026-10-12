/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x740ef0; label: FUN_00740ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00740ef0(int param_1,int param_2)

{
  int iVar1;
  char *in_ECX;
  
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar1 + param_2;
  if ((*in_ECX != '\0') && (*(int *)(in_ECX + 0xc) != 0)) {
    FUN_006e85b0(*(int *)(in_ECX + 0xc));
  }
  *(int *)(in_ECX + 4) = iVar1;
  *(int *)(in_ECX + 0xc) = iVar1;
  *(int *)(in_ECX + 8) = iVar1 + param_2;
  *in_ECX = '\0';
  return;
}

