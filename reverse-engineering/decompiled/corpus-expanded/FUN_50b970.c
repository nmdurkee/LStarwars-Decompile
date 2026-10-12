/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50b970; label: FUN_0050b970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0050b970(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (int)(param_2 + (param_2 >> 0x1f & 3U)) >> 2;
  iVar3 = 0x5c0999;
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar3 = iVar3 + *(int *)(param_1 + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return iVar3;
}

