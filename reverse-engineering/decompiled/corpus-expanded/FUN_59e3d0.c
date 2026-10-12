/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e3d0; label: FUN_0059e3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e3d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (DAT_0095642c < 0x10) {
    iVar3 = (-1 - param_1) * 0x70;
    iVar2 = iVar3;
    iVar5 = DAT_009562f8;
    do {
      iVar1 = (int)*(short *)(iVar2 + iVar5);
      if (iVar1 == param_1) {
        return;
      }
      if (*(short *)(iVar2 + iVar5) < 0) {
        FUN_0059e3d0(iVar1);
        iVar5 = DAT_009562f8;
      }
      else {
        (&DAT_009563d0)[DAT_0095642c] = iVar1;
        (&DAT_009562e8)[DAT_0095642c] = *(undefined1 *)(iVar5 + iVar3 + 0x60 + iVar4);
        DAT_0095642c = DAT_0095642c + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 2;
    } while (DAT_0095642c < 0x10);
  }
  return;
}

