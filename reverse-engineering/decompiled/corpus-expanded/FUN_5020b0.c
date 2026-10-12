/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x5020b0; label: FUN_005020b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005020b0(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x14);
  iVar3 = 0;
  if ((short)piVar2[1] != 0) {
    iVar4 = 0;
    do {
      pbVar1 = (byte *)(*piVar2 + 0x58 + iVar4);
      *pbVar1 = *pbVar1 | 2;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x5c;
    } while (iVar3 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  return;
}

