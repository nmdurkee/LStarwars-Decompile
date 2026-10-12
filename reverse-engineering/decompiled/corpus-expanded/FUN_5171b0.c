/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5171b0; label: FUN_005171b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005171b0(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  if ((param_1 != 0) && (pbVar2 = *(byte **)(param_1 + 0x10), pbVar2 != (byte *)0x0)) {
    if (param_2 == 0) {
      iVar3 = **(int **)(pbVar2 + 4);
LAB_00517205:
      if ((iVar3 != 0) && (iVar3 != *(int *)(pbVar2 + 8))) {
        *(int *)(pbVar2 + 8) = iVar3;
        return 1;
      }
    }
    else {
      iVar3 = 0;
      if (*pbVar2 != 0) {
        do {
          iVar1 = FUN_004f8b10(*(undefined4 *)(*(int *)(pbVar2 + 4) + iVar3 * 4),param_2);
          pbVar2 = *(byte **)(param_1 + 0x10);
          if (iVar1 == 0) {
            iVar3 = *(int *)(*(int *)(pbVar2 + 4) + iVar3 * 4);
            goto LAB_00517205;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)*pbVar2);
      }
    }
  }
  return 0;
}

