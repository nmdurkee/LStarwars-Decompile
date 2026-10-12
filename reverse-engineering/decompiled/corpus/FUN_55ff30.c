/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55ff30; label: FUN_0055ff30
 */

void FUN_0055ff30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  *(undefined4 *)(param_1 + 0x2aa8) = 0xffffffff;
  _sprintf(local_104,"%s.bri",param_1 + 0x80);
  iVar1 = thunk_FUN_004fa610(local_104);
  if (iVar1 != 0) {
    uVar2 = FUN_006893e0(local_104,*(undefined4 *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x2aa8) = uVar2;
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

