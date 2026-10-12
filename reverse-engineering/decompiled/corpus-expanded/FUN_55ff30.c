/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55ff30; label: FUN_0055ff30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

