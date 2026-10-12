/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x502620; label: FUN_00502620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00502620(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x58) + 0x14);
  uVar4 = (uint)*(ushort *)(piVar1 + 1);
  iVar3 = 0;
  if (uVar4 != 0) {
    pbVar2 = (byte *)(*piVar1 + 0x58);
    do {
      if (((*pbVar2 & 4) != 0) && ((*pbVar2 & 2) != 0)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
      pbVar2 = pbVar2 + 0x5c;
    } while (iVar3 < (int)uVar4);
  }
  return 0;
}

