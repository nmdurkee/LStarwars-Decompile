/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500c50; label: FUN_00500c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500c50(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int in_EDX;
  uint *unaff_ESI;
  
  *(undefined1 *)(in_EDX + 8) = 0;
  *(char *)(in_EDX + 9) = (char)unaff_ESI[4];
  *(undefined1 *)(in_EDX + 10) = 0;
  uVar4 = 0;
  if (*unaff_ESI != 0) {
    do {
      iVar3 = *(int *)(in_EDX + 4);
      pbVar2 = (byte *)(iVar3 + uVar4 * 4);
      *pbVar2 = *pbVar2 & 0xfd;
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined1 *)(iVar3 + iVar1 + 1) = 0;
    } while (uVar4 < *unaff_ESI);
  }
  return;
}

