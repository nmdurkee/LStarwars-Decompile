/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x502b40; label: FUN_00502b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00502b40(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = *(int **)(in_EAX + 0xa4);
  piVar2 = *(int **)(*(int *)(in_EAX + 0x58) + 0x18);
  if (((piVar2 != (int *)0x0) && ((short)piVar2[1] != 0)) && (iVar6 = 0, (short)piVar2[1] != 0)) {
    iVar4 = 0;
    iVar5 = 0;
    pcVar3 = DAT_009213a8;
    do {
      if (((*(byte *)(*piVar2 + iVar5 + 0x5c) & 2) != 0) && (pcVar3 != (code *)0x0)) {
        (*pcVar3)(*piVar2 + iVar5,*piVar1 + iVar4);
        pcVar3 = DAT_009213a8;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 100;
      iVar4 = iVar4 + 0x18;
    } while (iVar6 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  return;
}

