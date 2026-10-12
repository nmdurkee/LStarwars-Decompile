/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66b0c0; label: FUN_0066b0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0066b0c0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_8;
  int *local_4;
  
  iVar5 = -param_5;
  puVar6 = (undefined4 *)(param_2 + param_5 * -0xc + 8);
  local_8 = 0;
  local_4 = &DAT_02924b60;
  puVar4 = (undefined4 *)(param_3 + param_5 * -0x10 + 8);
  iVar2 = DAT_029620a4;
  do {
    if ((((param_1 == -1) || (*(char *)((int)local_4 + 0x41) == param_1)) &&
        (iVar3 = *local_4, iVar3 != -1)) &&
       ((iVar3 != 99999 && (iVar3 = iVar3 * 0x330, *(char *)(iVar3 + 0x2f5 + iVar2) != '\0')))) {
      iVar1 = *(int *)(DAT_0296209c + *(short *)(iVar3 + 0x182 + iVar2) * 4);
      if ((-1 < iVar5) && (iVar5 < param_4)) {
        if (param_2 != 0) {
          puVar6[-2] = *(undefined4 *)(iVar3 + 400 + iVar2);
          puVar6[-1] = *(undefined4 *)(iVar3 + 0x194 + DAT_029620a4);
          *puVar6 = *(undefined4 *)(iVar3 + 0x198 + DAT_029620a4);
          iVar2 = DAT_029620a4;
        }
        if (param_3 != 0) {
          puVar4[-2] = *(undefined4 *)(iVar1 + 0x3e0);
          puVar4[-1] = *(undefined4 *)(iVar1 + 0x3ec);
          *puVar4 = *(undefined4 *)(iVar1 + 0x3f8);
          puVar4[1] = *(undefined4 *)(iVar1 + 0x404);
          iVar2 = DAT_029620a4;
        }
      }
      local_8 = local_8 + 1;
      puVar6 = puVar6 + 3;
      puVar4 = puVar4 + 4;
      iVar5 = iVar5 + 1;
    }
    local_4 = local_4 + 0x16;
  } while ((int)local_4 < 0x292fb60);
  return local_8 - param_5;
}

