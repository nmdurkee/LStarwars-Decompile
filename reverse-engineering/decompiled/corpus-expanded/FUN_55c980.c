/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c980; label: FUN_0055c980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055c980(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 2;
  DAT_0093d500 = 0;
  pbVar1 = (byte *)(DAT_0093d504 + 0x12d4);
  iVar3 = 0x10;
  do {
    if ((pbVar1[-0x10d8] & 1) != 0) {
      DAT_0093d500 = iVar2 + -1;
    }
    if ((*pbVar1 & 1) != 0) {
      DAT_0093d500 = iVar2;
    }
    if ((pbVar1[0x10d8] & 1) != 0) {
      DAT_0093d500 = iVar2 + 1;
    }
    if ((pbVar1[0x21b0] & 1) != 0) {
      DAT_0093d500 = iVar2 + 2;
    }
    iVar2 = iVar2 + 4;
    pbVar1 = pbVar1 + 0x4360;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

