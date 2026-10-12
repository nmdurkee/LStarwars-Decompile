/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e1260; label: FUN_004e1260
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e1260(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  _memset(&DAT_00889010,0,0x78);
  _DAT_00889028 = FUN_0051acd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"landing_pad");
  iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088902c,"slave1",1);
  if (iVar2 != 0) {
    uVar3 = FUN_005cffb0(&DAT_0088902c);
    DAT_00889086 = FUN_0067c760(uVar3);
  }
  iVar6 = 1;
  piVar5 = &DAT_00889038;
  iVar2 = 4;
  do {
    _sprintf(local_14,"turret%d",iVar6);
    piVar4 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00805e24,local_14);
    if (piVar4 == (int *)0x0) {
      FUN_004ddc80(local_14);
    }
    else {
      iVar1 = *piVar4;
      *piVar5 = iVar1;
      *(undefined **)(iVar1 + 0xe4) = &DAT_0088905c;
      *(undefined1 *)(*piVar5 + 300) = 2;
      *(ushort *)(*piVar5 + 0x13a) = *(ushort *)(*piVar5 + 0x13a) | 1;
    }
    _sprintf(local_14,"R4_t%d",iVar6);
    piVar4 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f90d0,local_14);
    if (piVar4 == (int *)0x0) {
      FUN_004ddc80(local_14);
    }
    else {
      piVar5[5] = *piVar4;
    }
    iVar6 = iVar6 + 1;
    piVar5 = piVar5 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  DAT_00889010 = FUN_005ab050(DAT_0095df4c,"JangoFight",0,0);
  DAT_00889014 = FUN_005ab050(DAT_0095df4c,"Slave1CanFire",0,0);
  DAT_00889018 = FUN_005ab050(DAT_0095df4c,"ResetTurrets",0,0);
  DAT_0088901c = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  DAT_00889020 = FUN_005aac00(DAT_0095df4c,"MiniCutStarted",0);
  FUN_0057c970(*(undefined4 *)(param_1 + 0x2ab0),"Ep2_Kamino_Intro2");
  DAT_00889024 = FUN_0057c970(*(undefined4 *)(param_1 + 0x2ab0),"Ep2_Kamino_Intro2");
  __security_check_cookie(local_4 ^ (uint)local_14);
  return;
}

