/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55fe90; label: FUN_0055fe90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055fe90(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  *(undefined4 *)(param_1 + 0x2aa4) = 0xffffffff;
  if (DAT_00947bbc != 0) {
    _sprintf(local_104,"%s.gra",param_1 + 0x80);
    iVar1 = thunk_FUN_004fa610(local_104);
    if (iVar1 != 0) {
      uVar2 = FUN_00690f60(local_104,*(undefined4 *)(param_1 + 0x13c),
                           *(undefined4 *)(param_1 + 0x295c),param_1 + 0x104,param_1 + 0x108);
      *(undefined4 *)(param_1 + 0x2aa4) = uVar2;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

