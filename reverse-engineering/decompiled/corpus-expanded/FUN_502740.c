/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x502740; label: FUN_00502740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00502740(int param_1,undefined4 param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_4d;
  int local_4c;
  int local_48;
  int *local_44;
  undefined1 local_40 [64];
  
  local_44 = *(int **)(param_1 + 0xa0);
  piVar2 = *(int **)(*(int *)(param_1 + 0x58) + 0x14);
  iVar4 = 0;
  local_48 = 0;
  if ((short)piVar2[1] != 0) {
    local_4c = 0;
    do {
      bVar1 = *(byte *)(*piVar2 + 0x58 + iVar4);
      iVar6 = *local_44 + local_4c;
      iVar5 = *piVar2 + iVar4;
      if (((bVar1 & 4) != 0) && ((bVar1 & 2) == 0)) {
        iVar3 = *(int *)(iVar5 + 0x50);
        if ((iVar3 != 0) && (iVar3 = FUN_005da520(iVar3,iVar6 + 0xc,&local_4d,param_2), iVar3 != 0))
        {
          FUN_005cfc00(iVar6,local_4d != '\0');
        }
        iVar3 = FUN_005cfd60(iVar6);
        if (iVar3 != 0) {
          FUN_00502390(iVar5,param_2,local_40);
          if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
            FUN_005b5430(local_40,local_40,param_1 + 0x18);
          }
          FUN_005ea570(iVar6,local_40);
        }
      }
      local_4c = local_4c + 0x10;
      local_48 = local_48 + 1;
      iVar4 = iVar4 + 0x5c;
    } while (local_48 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  return;
}

