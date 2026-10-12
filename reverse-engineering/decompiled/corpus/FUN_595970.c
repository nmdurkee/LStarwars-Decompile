/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x595970; label: FUN_00595970
 */

void FUN_00595970(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  _sprintf(local_104,"%s.rtl",param_2);
  uVar1 = FUN_00635e40(local_104,param_1 + 0x104,*(undefined4 *)(param_1 + 0x108));
  *(undefined4 *)(param_1 + 0x2ab4) = uVar1;
  _sprintf(local_104,"%s.bur",param_2);
  uVar1 = FUN_006412b0(local_104,param_1 + 0x104,*(undefined4 *)(param_1 + 0x108));
  *(undefined4 *)(param_1 + 0x2aac) = uVar1;
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

