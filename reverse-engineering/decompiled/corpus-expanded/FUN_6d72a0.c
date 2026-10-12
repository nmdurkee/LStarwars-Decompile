/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d72a0; label: FUN_006d72a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006d72a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  
  local_18 = 0;
  iVar2 = param_2;
  do {
    iVar1 = FUN_006d43e0(3,param_1,iVar2);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 3) {
      iVar2 = 0;
    }
    local_18 = local_18 + 1;
  } while (local_18 < 3);
  FUN_006d45f0(iVar1,param_1,param_2,-1 < param_3,param_3);
  if ((-1 < param_3) && (param_1 - 10U < 4)) {
    iVar2 = 0;
    do {
      FUN_004f48e0(iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = FUN_006d7040(param_3,4);
    if (iVar2 != 0) {
      iVar1 = 0;
    }
  }
  return iVar1 != 0;
}

