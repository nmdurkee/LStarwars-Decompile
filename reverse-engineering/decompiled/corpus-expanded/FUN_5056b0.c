/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x5056b0; label: FUN_005056b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005056b0(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar5 = 0;
  if (0 < *(int *)(iVar2 + 8)) {
    iVar4 = 0;
    while( true ) {
      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar4 + *(int *)(iVar2 + 0xc)),param_2);
      if (iVar3 == 0) break;
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x34;
      if (*(int *)(iVar2 + 8) <= iVar5) {
        return iVar3;
      }
    }
    iVar2 = *(int *)(param_1 + 0xc);
    pbVar1 = (byte *)(iVar2 + 3 + iVar5 * 4);
    *pbVar1 = *pbVar1 | 1;
    param_1 = iVar2 + 3 + iVar5 * 4;
  }
  return param_1;
}

