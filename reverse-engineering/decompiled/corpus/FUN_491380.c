/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x491380; label: FUN_00491380
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00491380(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  _memset(&DAT_0087b370,0,0x150);
  puVar4 = &DAT_0087b3c0;
  iVar3 = 0;
  do {
    uVar1 = FUN_0051acd0(*(undefined4 *)(param_1 + 0x2ae8),
                         *(undefined4 *)((int)&PTR_s_MAINROOM_007fab24 + iVar3));
    *(undefined4 *)((int)&DAT_0087b370 + iVar3) = uVar1;
    uVar1 = FUN_0051ad20(*(undefined4 *)(param_1 + 0x2ae8),
                         *(undefined4 *)((int)&PTR_s_MAINROOM_007fab24 + iVar3));
    *(undefined4 *)((int)&DAT_0087b398 + iVar3) = uVar1;
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      _sprintf(local_24,"%s_%d",*(undefined4 *)((int)&PTR_s_MAINROOM_007fab24 + iVar3),iVar2);
      uVar1 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),local_24);
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < 4);
    iVar3 = iVar3 + 4;
  } while ((int)puVar4 < 0x87b460);
  DAT_0087b460 = 0xffff;
  DAT_0087b474 = FUN_005ab050(DAT_0095df4c,&DAT_0075ad14,0,0);
  DAT_0087b478 = FUN_005ab050(DAT_0095df4c,"ServingCustomer",0,0);
  _DAT_0087b466 = 0;
  iVar3 = 0;
  do {
    _sprintf(local_24,"CounterA_%d",iVar3);
    uVar1 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),local_24);
    (&DAT_0087b47c)[iVar3] = uVar1;
    _sprintf(local_24,"CounterB_%d",iVar3);
    iVar2 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),local_24);
    (&DAT_0087b48c)[iVar3] = iVar2;
    if (((&DAT_0087b47c)[iVar3] == 0) || (iVar2 == 0)) break;
    _DAT_0087b466 = _DAT_0087b466 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  _DAT_0087b4bc = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),"ServePlayer");
  _DAT_0087b464 = 0;
  DAT_0087b49c = 0;
  _DAT_0087b4a0 = 0;
  _DAT_0087b4a4 = 0;
  _DAT_0087b4a8 = 0;
  _DAT_0087b4ac = 0;
  _DAT_0087b4b0 = 0;
  _DAT_0087b4b4 = 0;
  _DAT_0087b4b8 = 0;
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

