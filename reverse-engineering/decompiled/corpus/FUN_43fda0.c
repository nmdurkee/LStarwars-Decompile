/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43fda0; label: FUN_0043fda0
 */

void FUN_0043fda0(int param_1)

{
  int iVar1;
  int iVar2;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  if (param_1 != 0) {
    FUN_005171b0(param_1,0);
    *(undefined4 *)(PTR_DAT_00802c54 + 0x2aec) = 0;
    iVar2 = 0;
    do {
      if (iVar2 == 0) {
        _sprintf(local_24,"Level");
      }
      else {
        _sprintf(local_24,"Level%d",iVar2);
      }
      iVar1 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_24,0,1,0);
      if (iVar1 != 0) {
        FUN_00514640(param_1,0,
                     PTR_DAT_00802c54 + *(int *)(PTR_DAT_00802c54 + 0x2aec) * 0xdc + 0x2b00,0,
                     local_24,0,0,0,0);
        FUN_004f1f10(PTR_DAT_00802c54 + *(int *)(PTR_DAT_00802c54 + 0x2aec) * 0xdc + 0x2af0,local_24
                    );
        FUN_0048a310(PTR_DAT_00802c54,
                     PTR_DAT_00802c54 + *(int *)(PTR_DAT_00802c54 + 0x2aec) * 0xdc + 0x2af0);
        *(int *)(PTR_DAT_00802c54 + 0x2aec) = *(int *)(PTR_DAT_00802c54 + 0x2aec) + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x20);
    FUN_0043b730(param_1);
    FUN_0043cc30(*(undefined4 *)(PTR_DAT_00802c54 + 0x4670));
    FUN_005ab0f0(PTR_DAT_00802c54,*(undefined4 *)(PTR_DAT_00802c54 + 0x4674));
    FUN_0041fe90(param_1);
    FUN_0041c620(param_1);
    if (*(int *)(PTR_DAT_00802c54 + 0x2aec) != 0) {
      FUN_0055af20(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                   *(undefined4 *)(PTR_DAT_00802c54 + 0x2acc),PTR_DAT_00802c54);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

