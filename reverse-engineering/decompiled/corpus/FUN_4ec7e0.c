/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ec7e0; label: FUN_004ec7e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec7e0(void)

{
  int iVar1;
  char *pcVar2;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  _memset(&DAT_0088a6d0,0,0x400);
  DAT_0088a628 = FUN_00578750(0x14);
  DAT_0088aaac = '\0';
  do {
    if (DAT_0088aaac < '\t') {
      pcVar2 = "dot_off_0%d";
    }
    else {
      pcVar2 = "dot_off_%d";
    }
    _sprintf(local_24,pcVar2,DAT_0088aaac + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a6d4 + DAT_0088aaac * 0xc,
                 local_24,1);
    if (DAT_0088aaac < '\t') {
      pcVar2 = "dot_flash_0%d";
    }
    else {
      pcVar2 = "dot_flash_%d";
    }
    _sprintf(local_24,pcVar2,DAT_0088aaac + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a794 + DAT_0088aaac * 0xc,
                 local_24,1);
    if (DAT_0088aaac < '\t') {
      pcVar2 = "dot_select_0%d";
    }
    else {
      pcVar2 = "dot_select_%d";
    }
    _sprintf(local_24,pcVar2,DAT_0088aaac + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a854 + DAT_0088aaac * 0xc,
                 local_24,1);
    if (DAT_0088aaac < '\t') {
      pcVar2 = "dot_on_0%d";
    }
    else {
      pcVar2 = "dot_on_%d";
    }
    _sprintf(local_24,pcVar2,DAT_0088aaac + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a914 + DAT_0088aaac * 0xc,
                 local_24,1);
    if (DAT_0088aaac < '\t') {
      pcVar2 = "dot_finish_0%d";
    }
    else {
      pcVar2 = "dot_finish_%d";
    }
    _sprintf(local_24,pcVar2,DAT_0088aaac + 1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a9d4 + DAT_0088aaac * 0xc,
                 local_24,1);
    iVar1 = FUN_005cfac0(&DAT_0088a6d4 + DAT_0088aaac * 0xc);
    if ((((iVar1 == 0) || (iVar1 = FUN_005cfac0(&DAT_0088a794 + DAT_0088aaac * 0xc), iVar1 == 0)) ||
        (iVar1 = FUN_005cfac0(&DAT_0088a854 + DAT_0088aaac * 0xc), iVar1 == 0)) ||
       ((iVar1 = FUN_005cfac0(&DAT_0088a914 + DAT_0088aaac * 0xc), iVar1 == 0 ||
        (iVar1 = FUN_005cfac0(&DAT_0088a9d4 + DAT_0088aaac * 0xc), iVar1 == 0)))) break;
    if ((DAT_0088aaac == '\0') && (iVar1 = FUN_005cf9c0(&DAT_0088a6d4), iVar1 != 0)) {
      _DAT_0088aab4 = *(undefined4 *)(iVar1 + 4);
      _DAT_0088aab8 = *(undefined4 *)(iVar1 + 4);
    }
    DAT_0088aaac = DAT_0088aaac + '\x01';
  } while (DAT_0088aaac < '\x10');
  DAT_0088a6d0 = FUN_0051acd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"DISCO");
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087aad8,"force_engine_lump",1);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087aae4,"disco_base",1);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

