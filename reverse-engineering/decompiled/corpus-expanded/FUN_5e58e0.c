/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e58e0; label: FUN_005e58e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005e58e0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  iVar3 = in_ECX[1];
  piVar1 = (int *)(iVar3 + 0x24 + iVar2 * 0x28);
  *piVar1 = *piVar1 + -1;
  return iVar3 + iVar2 * 0x28;
}

