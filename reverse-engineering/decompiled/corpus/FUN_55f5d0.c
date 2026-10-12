/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f5d0; label: FUN_0055f5d0
 */

void FUN_0055f5d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  if (*(int *)(param_1 + 0x2aa0) == -1) {
    _sprintf(local_104,"%s.anm",param_1 + 0x80);
    iVar1 = thunk_FUN_004fa610(local_104);
    if (iVar1 != 0) {
      uVar2 = FUN_00687850(local_104,*(undefined4 *)(param_1 + 0x13c));
      *(undefined4 *)(param_1 + 0x2aa0) = uVar2;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

