/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505600; label: FUN_00505600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505600(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar4 = 0;
  if (0 < *(int *)(iVar1 + 8)) {
    iVar3 = 0;
    while( true ) {
      iVar2 = FUN_004f8b10(*(undefined4 *)(iVar3 + *(int *)(iVar1 + 0xc)),param_2);
      if (iVar2 == 0) break;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x34;
      if (*(int *)(iVar1 + 8) <= iVar4) {
        return;
      }
    }
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 2 + iVar4 * 4) = 0xff;
  }
  return;
}

