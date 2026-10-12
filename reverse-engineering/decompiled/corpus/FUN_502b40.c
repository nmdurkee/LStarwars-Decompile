/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502b40; label: FUN_00502b40
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

