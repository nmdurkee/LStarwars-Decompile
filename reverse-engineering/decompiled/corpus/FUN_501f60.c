/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x501f60; label: FUN_00501f60
 */

void FUN_00501f60(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  piVar1 = *(int **)(in_EAX + 0x14);
  piVar2 = *(int **)(in_EAX + 0x1c);
  if ((param_1 != 0) && ((short)piVar1[1] != 0)) {
    iVar5 = 0;
    iVar4 = 0;
    do {
      iVar6 = *piVar1 + iVar5;
      iVar3 = FUN_005cf5b0(param_1,&local_c,*(undefined4 *)(*piVar1 + 0x40 + iVar5),1);
      if (iVar3 == 0) {
        FUN_004fff10(*(undefined4 *)(iVar6 + 0x40));
      }
      else {
        *(byte *)(iVar6 + 0x58) = *(byte *)(iVar6 + 0x58) | 4;
        *(undefined4 *)(iVar6 + 0x44) = local_c;
        if (local_4 == 0) {
          *(undefined4 *)(iVar6 + 0x48) = local_8;
        }
        else {
          *(int *)(iVar6 + 0x48) = local_4;
        }
      }
      if ((*(char *)(iVar6 + 0x59) == '\0') || (iVar3 = *(int *)(iVar6 + 0x54), 0xfe < iVar3)) {
        *(undefined1 *)(iVar6 + 0x5a) = 0xff;
      }
      else {
        *(char *)(iVar6 + 0x5a) = (char)iVar3;
        *(int *)(iVar6 + 0x54) = iVar3 * 100 + *piVar2;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x5c;
    } while (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1));
  }
  return;
}

