/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c0c80; label: FUN_004c0c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c0c80(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x5094)) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x5090) + 0x3c);
    do {
      bVar1 = *pbVar2;
      if ((((bVar1 & 8) == 0) && ((bVar1 & 4) != 0)) && (*(int *)(pbVar2 + 8) == param_2)) {
        pbVar2[4] = 0;
        pbVar2[5] = 0;
        pbVar2[6] = 0;
        pbVar2[7] = 0;
        *pbVar2 = bVar1 & 0xfb;
        pbVar2[8] = 0;
        pbVar2[9] = 0;
        pbVar2[10] = 0;
        pbVar2[0xb] = 0;
      }
      iVar3 = iVar3 + 1;
      pbVar2 = pbVar2 + 0x54;
    } while (iVar3 < *(int *)(param_1 + 0x5094));
  }
  return;
}

