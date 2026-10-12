/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57d050; label: FUN_0057d050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057d050(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x18);
  iVar4 = 0;
  piVar2 = *(int **)(param_1 + 0xa4);
  if (*(short *)(iVar1 + 4) != 0) {
    iVar5 = 0;
    do {
      iVar3 = *piVar2;
      *(undefined4 *)(iVar3 + 4 + iVar5) = 0;
      iVar3 = iVar3 + iVar5;
      *(undefined1 *)(iVar3 + 0x14) = 0;
      *(undefined1 *)(iVar3 + 0x15) = 0xff;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x18;
    } while (iVar4 < (int)(uint)*(ushort *)(iVar1 + 4));
  }
  return;
}

