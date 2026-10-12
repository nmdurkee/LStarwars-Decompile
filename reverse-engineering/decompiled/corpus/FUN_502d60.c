/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502d60; label: FUN_00502d60
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

