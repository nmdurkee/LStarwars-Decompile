/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f1fc0; label: FUN_005f1fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005f1fc0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar3 = *in_ECX;
  if (-1 < iVar3) {
    iVar2 = in_ECX[1];
    piVar1 = (int *)(iVar2 + 0x24 + iVar3 * 0x28);
    *piVar1 = *piVar1 + -1;
    iVar3 = iVar2 + iVar3 * 0x28;
  }
  return iVar3;
}

