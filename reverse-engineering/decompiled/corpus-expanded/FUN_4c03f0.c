/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c03f0; label: FUN_004c03f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c03f0(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x5094)) {
    iVar3 = 0;
    do {
      pbVar1 = (byte *)(*(int *)(param_1 + 0x5090) + 0x3c + iVar3);
      *pbVar1 = *pbVar1 & 0xdf;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x54;
    } while (iVar2 < *(int *)(param_1 + 0x5094));
  }
  return;
}

