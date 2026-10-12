/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505590; label: FUN_00505590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505590(int param_1,undefined4 param_2,char param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar6 = 0;
  if (0 < *(int *)(iVar2 + 8)) {
    iVar5 = 0;
    while( true ) {
      iVar4 = FUN_004f8b10(*(undefined4 *)(iVar5 + *(int *)(iVar2 + 0xc)),param_2);
      if (iVar4 == 0) break;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x34;
      if (*(int *)(iVar2 + 8) <= iVar6) {
        return;
      }
    }
    bVar3 = '\x01' << (param_3 - 1U & 0x1f);
    pbVar1 = (byte *)(*(int *)(param_1 + 0xc) + 2 + iVar6 * 4);
    if (param_4 != 0) {
      *pbVar1 = *pbVar1 | bVar3;
      return;
    }
    *pbVar1 = *pbVar1 & ~bVar3;
  }
  return;
}

