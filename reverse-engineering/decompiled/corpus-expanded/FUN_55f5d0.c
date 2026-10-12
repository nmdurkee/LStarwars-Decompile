/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f5d0; label: FUN_0055f5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

