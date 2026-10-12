/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ed6e0; label: FUN_004ed6e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ed6e0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  DAT_0088aaec = 0;
  DAT_0088aad0 = 0;
  DAT_0087a7f0 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"cannon_1");
  iVar7 = 1;
  puVar5 = &DAT_0087ab98;
  iVar6 = 2;
  do {
    _sprintf(local_24,"cover_%d",iVar7);
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5,local_24,1);
    _sprintf(local_24,"cover_%d1",iVar7);
    piVar3 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,local_24);
    if (piVar3 != (int *)0x0) {
      iVar2 = *piVar3;
      (&DAT_0088a638)[DAT_0088aad0] = iVar2;
      puVar1 = (uint *)(iVar2 + 0x94);
      *puVar1 = *puVar1 | 0x8000000;
      DAT_0088aad0 = DAT_0088aad0 + 1;
      FUN_00567da0(*piVar3);
    }
    puVar5 = puVar5 + 0xc;
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
    _sprintf(local_24,"spinner%d_null_1",iVar6);
    puVar4 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,local_24);
    if (puVar4 != (undefined4 *)0x0) {
      (&DAT_0088a638)[DAT_0088aad0] = *puVar4;
      DAT_0088aad0 = DAT_0088aad0 + 1;
      FUN_00567da0(*puVar4);
    }
  } while (iVar6 < 2);
  iVar6 = 0;
  puVar4 = &DAT_0087aad8;
  do {
    iVar6 = iVar6 + 1;
    _sprintf(local_24,"shot_0%d",iVar6);
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar4,local_24,1);
    puVar4 = puVar4 + 3;
  } while ((int)puVar4 < 0x87ab38);
  iVar6 = 0;
  puVar5 = &DAT_0087ab38;
  do {
    iVar6 = iVar6 + 1;
    _sprintf(local_24,"shot_0%da",iVar6);
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5,local_24,1);
    puVar5 = puVar5 + 0xc;
  } while ((int)puVar5 < 0x87ab98);
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f90d0,"panel2");
  iVar6 = 0;
  puVar5 = &DAT_0087ab38;
  do {
    FUN_005cfc00(puVar5 + -0x60,DAT_0088aaf0 <= iVar6);
    FUN_005cfc00(puVar5,iVar6 < DAT_0088aaf0);
    puVar5 = puVar5 + 0xc;
    iVar6 = iVar6 + 1;
  } while ((int)puVar5 < 0x87ab98);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

