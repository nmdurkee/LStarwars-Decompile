/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502670; label: FUN_00502670
 */

void FUN_00502670(int *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_4;
  
  iVar4 = 0;
  local_4 = 0;
  if ((short)param_2[1] != 0) {
    iVar3 = 0;
    do {
      iVar2 = *param_2;
      iVar5 = *param_1 + iVar3;
      *(undefined1 *)(iVar5 + 0xc) = 0;
      bVar1 = *(byte *)(iVar2 + iVar4 + 0x58);
      if ((bVar1 & 4) != 0) {
        if ((bVar1 & 2) == 0) {
          FUN_005cfc00(iVar5,(bVar1 & 1) != 0);
          FUN_005ea570(iVar5,iVar2 + iVar4);
        }
        else {
          *(byte *)(iVar5 + 0xd) = bVar1 & 1;
        }
      }
      local_4 = local_4 + 1;
      iVar4 = iVar4 + 0x5c;
      iVar3 = iVar3 + 0x10;
    } while (local_4 < *(ushort *)(param_2 + 1));
  }
  return;
}

