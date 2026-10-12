/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x502670; label: FUN_00502670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

