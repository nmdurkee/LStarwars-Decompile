/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56a8c0; label: FUN_0056a8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056a8c0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_118 [164];
  int local_74;
  float local_68;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_118;
  if (((param_1 != 0) && (param_2 != -1)) && (param_2 <= *(int *)(param_1 + 0x50bc))) {
    iVar2 = param_2 * 0x100 + *(int *)(param_1 + 0x50c4) + 0xd8;
    iVar1 = FUN_004f1ff0(iVar2);
    if (((iVar1 != 0) && (iVar2 != 0)) && (iVar2 = FUN_005689f0(iVar2,param_1), iVar2 != 0)) {
      _memset(local_118,0,0x114);
      uVar3 = 7;
      if (0.0 < local_68) {
        uVar3 = 0xf;
      }
      local_74 = iVar2;
      FUN_005672d0(param_3,local_118,0,uVar3,0);
      FUN_00547930(0x33,param_3,0,0);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_118);
  return;
}

