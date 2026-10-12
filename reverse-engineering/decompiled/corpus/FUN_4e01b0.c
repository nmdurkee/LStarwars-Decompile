/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e01b0; label: FUN_004e01b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e01b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined *puVar6;
  char *pcVar7;
  int local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  local_28 = param_1;
  _memset(&DAT_008890a8,0,1000);
  DAT_00882b74 = FUN_00578750(0xe);
  DAT_0088947c = '\0';
  do {
    if (DAT_0088947c < '\t') {
      pcVar7 = "dot_off_0%d";
    }
    else {
      pcVar7 = "dot_off_%d";
    }
    _sprintf(local_24,pcVar7,DAT_0088947c + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008890ac + DAT_0088947c * 0xc,
                 local_24,1);
    if (DAT_0088947c < '\t') {
      pcVar7 = "dot_flash_0%d";
    }
    else {
      pcVar7 = "dot_flash_%d";
    }
    _sprintf(local_24,pcVar7,DAT_0088947c + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088916c + DAT_0088947c * 0xc,
                 local_24,1);
    if (DAT_0088947c < '\t') {
      pcVar7 = "dot_select_0%d";
    }
    else {
      pcVar7 = "dot_select_%d";
    }
    _sprintf(local_24,pcVar7,DAT_0088947c + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088922c + DAT_0088947c * 0xc,
                 local_24,1);
    if (DAT_0088947c < '\t') {
      pcVar7 = "dot_finish_0%d";
    }
    else {
      pcVar7 = "dot_finish_%d";
    }
    _sprintf(local_24,pcVar7,DAT_0088947c + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008892ec + DAT_0088947c * 0xc,
                 local_24,1);
    if (DAT_0088947c < '\t') {
      pcVar7 = "dot_on_0%d";
    }
    else {
      pcVar7 = "dot_on_%d";
    }
    _sprintf(local_24,pcVar7,DAT_0088947c + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008893ac + DAT_0088947c * 0xc,
                 local_24,1);
    iVar2 = FUN_005cfac0(&DAT_008890ac + DAT_0088947c * 0xc);
    if (iVar2 == 0) break;
    iVar2 = FUN_005cfac0(&DAT_0088916c + DAT_0088947c * 0xc);
    if (iVar2 == 0) break;
    iVar2 = FUN_005cfac0(&DAT_0088922c + DAT_0088947c * 0xc);
    if (iVar2 == 0) break;
    iVar2 = FUN_005cfac0(&DAT_008892ec + DAT_0088947c * 0xc);
    if (iVar2 == 0) break;
    DAT_0088947c = DAT_0088947c + '\x01';
  } while (DAT_0088947c < '\x10');
  DAT_008890a8 = FUN_0051acd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"DISCO");
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882b14,"walllights1",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882b20,"walllights2",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882b48,"walllights1_disco",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882b54,"walllights2_disco",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882bac,"striplights1",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882bb8,"striplights1b",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882af8,"discolight1",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882b04,"discolight2",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00889004,"discorm_wall_on",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_00882b9c,"discorm_wall_off",1);
  iVar5 = 1;
  puVar4 = &DAT_0088908c;
  puVar6 = &DAT_00882b78;
  iVar2 = 3;
  do {
    _sprintf(local_24,"disco_on_spin%d",iVar5 + 2);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar6,local_24,1);
    if (DAT_00951b50 == 0) {
      _sprintf(local_24,"disco_off%d",iVar5);
      uVar3 = FUN_0055a020(*(undefined4 *)(local_28 + 0x2ac8),DAT_007f8cc4,local_24);
      *puVar4 = uVar3;
    }
    iVar1 = local_28;
    puVar6 = puVar6 + 0xc;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (DAT_00951b50 == 0) {
    DAT_00882b6c = FUN_0055a020(*(undefined4 *)(local_28 + 0x2ac8),DAT_00805e24,"turret01");
    DAT_00882b70 = FUN_0055a020(*(undefined4 *)(iVar1 + 0x2ac8),DAT_00805e24,"turret02");
    DAT_0087a96c = FUN_0055a020(*(undefined4 *)(iVar1 + 0x2ac8),DAT_00805d44,"msg_KaminoCProgress");
    DAT_0087a970 = FUN_0055a020(*(undefined4 *)(iVar1 + 0x2ac8),DAT_00802644,"JANGOFIELD01");
  }
  _DAT_00882af4 = 0;
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

