/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618550; label: FUN_00618550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00618550(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,undefined4 param_6,char *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int local_410;
  int local_40c;
  undefined4 local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_410;
  if (DAT_02912eb8 == 0) {
    iVar1 = FUN_006e6b90();
    local_408 = FUN_006e6b90();
    local_40c = FUN_006e6b90();
    iVar2 = FUN_006e6b90();
    FUN_005d0880(2);
    _vsprintf(local_404,param_7,&stack0x00000020);
    FUN_005d0d60(param_1,local_404);
    iVar3 = FUN_006e6b90();
    if (param_4 != 0x10) {
      if (param_4 == 0x20) {
        iVar1 = iVar1 - iVar3;
      }
      else if (param_4 == 0x40) {
        iVar1 = iVar1 - iVar3 / 2;
      }
    }
    local_410 = iVar1;
    if (iVar1 < local_40c) {
      local_410 = local_40c;
    }
    iVar1 = FUN_004f1ff0(local_404);
    for (pcVar4 = local_404 + iVar1 + -1; (iVar2 < iVar3 && (local_404 < pcVar4));
        pcVar4 = pcVar4 + -1) {
      *pcVar4 = '\0';
      FUN_005d0d60(param_1,local_404);
      iVar3 = FUN_006e6b90();
    }
    FUN_005eabb0(param_1,(float)local_410,(float)local_408,0);
    FUN_005f3510(param_1,local_404);
    FUN_005d08c0();
  }
  __security_check_cookie(local_4 ^ (uint)&local_410);
  return;
}

