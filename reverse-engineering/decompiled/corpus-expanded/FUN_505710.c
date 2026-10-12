/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505710; label: FUN_00505710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505710(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 8);
    iVar5 = 0;
    if (0 < *(int *)(iVar2 + 8)) {
      iVar4 = 0;
      while (iVar3 = FUN_004f8b10(*(undefined4 *)(*(int *)(iVar2 + 0xc) + iVar4),param_2),
            iVar3 != 0) {
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x34;
        if (*(int *)(iVar2 + 8) <= iVar5) {
          return;
        }
      }
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 2 + iVar5 * 4) =
           *(undefined1 *)(iVar5 * 0x34 + 10 + *(int *)(iVar2 + 0xc));
      pbVar1 = (byte *)(*(int *)(param_1 + 0xc) + 3 + iVar5 * 4);
      *pbVar1 = *pbVar1 & 0xfe;
    }
  }
  return;
}

