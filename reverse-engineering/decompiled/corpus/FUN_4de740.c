/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4de740; label: FUN_004de740
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de740(int param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  bool bVar6;
  int local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  iVar1 = FUN_0058a900(DAT_009553d4);
  if ((iVar1 == 0) && (DAT_00951b50 == 0)) {
    if (0 < DAT_00888ed0) {
      puVar2 = &DAT_00882c2c;
      iVar1 = 0;
      do {
        *puVar2 = *puVar2 & 0xffffffe6;
        puVar2[-0x12] = 0;
        puVar2[-0x13] = 0xffffffff;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 0x18;
      } while (iVar1 < DAT_00888ed0);
    }
    iVar1 = 0;
    if (0 < DAT_00888ed2) {
      puVar2 = &DAT_00888c2c;
      do {
        *puVar2 = *puVar2 & 0xfffffffe;
        puVar2[-0x12] = 0;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 0x18;
      } while (iVar1 < DAT_00888ed2);
    }
    iVar1 = 0;
    FUN_00414f20();
    iVar4 = 1;
    local_28 = 3;
    puVar5 = &DAT_00888eec;
    do {
      _sprintf(local_24,"pillar%d_01a",iVar4);
      FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5 + -0xc,local_24,1);
      _sprintf(local_24,"pillar%d_01b",iVar4);
      FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5,local_24,1);
      _sprintf(local_24,"pillar%d_01c",iVar4);
      FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5 + 0xc,local_24,1);
      _sprintf(local_24,"pillar%d_01ba",iVar4);
      FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5 + 0x18,local_24,1);
      iVar3 = 0;
      bVar6 = DAT_0093b2a4 == 0;
      *(undefined4 *)((int)&DAT_00888f70 + iVar1) = 0;
      if (bVar6) {
        do {
          if (((&DAT_0093d7f0)[iVar3] != 0) &&
             (*(short *)((&DAT_0093d7f0)[iVar3] + 0x1064) ==
              **(short **)((int)&PTR_DAT_007fff9c + iVar1))) {
            *(undefined4 *)((int)&DAT_00888f70 + iVar1) = (&DAT_0093d7f0)[iVar3];
            break;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 8);
      }
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x30;
      iVar1 = iVar1 + 4;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
    DAT_00888f7c = FUN_005ab050(DAT_0095df4c,"Phase",0,0);
    DAT_00888f80 = FUN_005ab050(DAT_0095df4c,"PhaseComplete",0,0);
    DAT_00888f84 = FUN_005ab050(DAT_0095df4c,"ObjectivesLeft",0,0);
    DAT_00888f88 = FUN_005ab050(DAT_0095df4c,"RestrainPadme",0,0);
    DAT_00888f8c = FUN_005ab050(DAT_0095df4c,"RestrainAnakin",0,0);
    DAT_00888f90 = FUN_005ab050(DAT_0095df4c,"RestrainObiWan",0,0);
    _DAT_00888fb8 = _DAT_00888fb8 & 0xfffffffc;
    DAT_00888fa8 = 0;
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

