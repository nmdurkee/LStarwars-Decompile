/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x502d60; label: FUN_00502d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00502d60(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = *(int **)(in_EAX + 0xa4);
  piVar2 = *(int **)(*(int *)(in_EAX + 0x58) + 0x18);
  iVar7 = 0;
  if ((short)piVar2[1] != 0) {
    iVar6 = 0;
    iVar5 = 0;
    pcVar4 = DAT_00921390;
    do {
      piVar3 = (int *)(*piVar1 + iVar5);
      if ((*piVar3 != 0) && (pcVar4 != (code *)0x0)) {
        (*pcVar4)(piVar3,*piVar2 + iVar6);
        pcVar4 = DAT_00921390;
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x18;
      iVar6 = iVar6 + 100;
    } while (iVar7 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  return;
}

