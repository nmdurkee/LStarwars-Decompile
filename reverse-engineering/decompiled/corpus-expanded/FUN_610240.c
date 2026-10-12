/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610240; label: FUN_00610240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610240(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_00610010("V2SessionManager::RemoveAllPeers() called");
  iVar2 = in_ECX[0x25];
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    (**(code **)(*in_ECX + 0x18))(iVar2,param_1);
    iVar2 = iVar1;
  }
  if (in_ECX[0x21] != 0) {
    (**(code **)(*in_ECX + 0x18))(in_ECX[0x21],param_1);
  }
  return;
}

