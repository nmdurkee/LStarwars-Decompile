/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571a50; label: FUN_00571a50
 */

void FUN_00571a50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  *(undefined4 *)(param_1 + 0x2a9c) = 0xffffffff;
  FUN_006489c0(*(undefined4 *)(param_1 + 0x2a98));
  if ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 0xe0) == 0) {
    _sprintf(local_104,"%s.par",param_1 + 0x80);
    iVar1 = thunk_FUN_004fa610(local_104);
    if (0 < iVar1) {
      uVar2 = FUN_0064c6c0(local_104,1,*(undefined4 *)(param_1 + 0x13c));
      *(undefined4 *)(param_1 + 0x2a9c) = uVar2;
    }
    uVar2 = FUN_00571890(param_1 + 0x104,param_1 + 0x108,0x40,DAT_00950ff8,DAT_00950ffc,
                         *(undefined4 *)(param_1 + 0x2a9c));
    *(undefined4 *)(param_1 + 0x138) = uVar2;
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

