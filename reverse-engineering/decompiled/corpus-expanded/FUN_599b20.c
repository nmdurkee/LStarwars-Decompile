/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x599b20; label: FUN_00599b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00599b20(int *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_64;
  uint *local_60;
  int local_5c [6];
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_64;
  local_60 = param_3;
  if (*param_1 == 0) {
    *(undefined1 *)((int)param_1 + 9) = 0xff;
    __security_check_cookie(local_4 ^ (uint)&local_64);
    return;
  }
  local_5c[0] = 0;
  local_5c[1] = 0;
  local_5c[2] = 0;
  local_5c[3] = 0;
  local_5c[4] = 0;
  local_5c[5] = 0;
  uVar3 = *param_3 + 3 & 0xfffffffc;
  *param_3 = uVar3;
  param_1[1] = uVar3;
  *(undefined1 *)(param_1 + 2) = 0;
  local_64 = 0;
  if (0 < param_2) {
    do {
      iVar7 = 0;
      iVar6 = local_64;
      do {
        _sprintf(local_44,"%s_%s_%i",
                 *(undefined4 *)(*(short *)((int)param_1 + 10) * 0x4c + 0xc + DAT_0093b274),
                 (&PTR_DAT_00805244)[iVar7],iVar6);
        iVar4 = FUN_005cf5b0(*param_1,(uint)*(byte *)(param_1 + 2) * 0x68 + param_1[1],local_44,1);
        if (iVar4 != 0) {
          puVar5 = (undefined4 *)FUN_005d0370((uint)*(byte *)(param_1 + 2) * 0x68 + param_1[1]);
          puVar8 = (undefined4 *)((uint)*(byte *)(param_1 + 2) * 0x68 + 0xc + param_1[1]);
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar8 = puVar8 + 1;
          }
          *(char *)((uint)*(byte *)(param_1 + 2) * 0x68 + 100 + param_1[1]) = (char)iVar7;
          bVar1 = *(byte *)(param_1 + 2);
          iVar4 = local_5c[iVar7];
          iVar6 = param_1[1];
          local_5c[iVar7] = local_5c[iVar7] + 1;
          *(char *)((uint)bVar1 * 0x68 + 0x67 + iVar6) = (char)iVar4;
          *(char *)(param_1 + 2) = (char)param_1[2] + '\x01';
          iVar6 = local_64;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
      local_64 = iVar6 + 1;
    } while (local_64 < param_2);
  }
  puVar2 = local_60;
  _sprintf(local_44,"%s_shadow",
           *(undefined4 *)(*(short *)((int)param_1 + 10) * 0x4c + 0xc + DAT_0093b274));
  FUN_005cf5b0(*param_1,param_1 + 3,local_44,1);
  if (*(byte *)(param_1 + 2) == 0) {
    param_1[1] = 0;
    __security_check_cookie(local_4 ^ (uint)&local_64);
    return;
  }
  *puVar2 = *puVar2 + (uint)*(byte *)(param_1 + 2) * 0x68;
  __security_check_cookie(local_4 ^ (uint)&local_64);
  return;
}

