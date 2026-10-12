/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7630; label: FUN_004e7630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7630(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_18;
  local_18 = 0xffffffff;
  FUN_005cf5b0(DAT_00924898,&DAT_0088a2f4,"Gun_Turret_icon",1);
  DAT_0088a532 = '\0';
  _DAT_0088a2f0 = 0;
  _memset(&DAT_0088a290,0,0x60);
  _memset(&DAT_0088a290,0,0x30);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a290,"rebelcruiser2",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a29c,"transport3",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2a8,"transport2",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2c0,"transport1",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2cc,"rebelcruiser1",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2d8,"transport4",0);
  iVar3 = 0;
  do {
    iVar1 = iVar3 + 1;
    _sprintf(local_14,"turret%d",iVar1);
    puVar2 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00805e24,local_14);
    if (puVar2 != (undefined4 *)0x0) {
      (&DAT_0088a3c8)[iVar3] = *puVar2;
    }
    if ((&DAT_0088a3c8)[iVar3] == 0) {
      (&DAT_0088a3c8)[iVar3] = 0;
    }
    else {
      DAT_0088a532 = DAT_0088a532 + '\x01';
      *(undefined4 *)((&DAT_0088a3c8)[iVar3] + 0xfc) = 0x3f000000;
    }
    iVar3 = iVar1;
  } while (iVar1 < 0x10);
  FUN_004ba680(&local_18,&DAT_0088a532,1,1,0);
  DAT_00800224 = 0;
  __security_check_cookie(local_4 ^ (uint)&local_18);
  return;
}

