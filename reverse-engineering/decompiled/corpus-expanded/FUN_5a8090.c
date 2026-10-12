/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8090; label: FUN_005a8090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8090(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  *(undefined4 *)(param_1 + 0x2a98) = 0xffffffff;
  _sprintf(local_104,"%s.ptl",param_1 + 0x80);
  iVar1 = thunk_FUN_004fa610(local_104);
  if (iVar1 != 0) {
    uVar2 = FUN_0068df20(local_104,1,*(undefined4 *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x2a98) = uVar2;
  }
  uVar2 = FUN_0062c400(param_1 + 0x104,param_1 + 0x108,param_3,param_4,param_2,
                       *(undefined4 *)(param_1 + 0x2a98));
  *(undefined4 *)(param_1 + 0x134) = uVar2;
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

