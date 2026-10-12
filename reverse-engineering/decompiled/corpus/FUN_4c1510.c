/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c1510; label: FUN_004c1510
 */

void FUN_004c1510(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  iVar2 = 0x61;
  puVar4 = &DAT_0087bbc8;
  iVar3 = 0x1a;
  do {
    iVar1 = iVar3;
    local_14[0] = '\0';
    local_14[1] = '\0';
    local_14[2] = '\0';
    local_14[3] = '\0';
    local_14[4] = '\0';
    local_14[5] = '\0';
    local_14[6] = '\0';
    local_14[7] = '\0';
    local_14[8] = '\0';
    local_14[9] = '\0';
    local_14[10] = '\0';
    local_14[0xb] = '\0';
    local_14[0xc] = '\0';
    local_14[0xd] = '\0';
    local_14[0xe] = '\0';
    local_14[0xf] = '\0';
    _sprintf(local_14,"shop_%c",iVar2);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar4,local_14,1);
    iVar2 = iVar2 + 1;
    puVar4 = puVar4 + 3;
    iVar3 = iVar1 + -1;
  } while (iVar1 + -1 != 0);
  iVar3 = iVar1 + 0x2f;
  puVar5 = &DAT_0087bd00;
  iVar1 = iVar1 + 9;
  do {
    local_14[0] = '\0';
    local_14[1] = '\0';
    local_14[2] = '\0';
    local_14[3] = '\0';
    local_14[4] = '\0';
    local_14[5] = '\0';
    local_14[6] = '\0';
    local_14[7] = '\0';
    local_14[8] = '\0';
    local_14[9] = '\0';
    local_14[10] = '\0';
    local_14[0xb] = '\0';
    local_14[0xc] = '\0';
    local_14[0xd] = '\0';
    local_14[0xe] = '\0';
    local_14[0xf] = '\0';
    _sprintf(local_14,"shop_%c",iVar3);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar5,local_14,1);
    iVar3 = iVar3 + 1;
    puVar5 = puVar5 + 0xc;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  __security_check_cookie(local_4 ^ (uint)local_14);
  return;
}

