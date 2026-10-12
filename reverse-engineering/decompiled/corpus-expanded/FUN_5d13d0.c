/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d13d0; label: FUN_005d13d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d13d0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_504 [256];
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_504;
  _sprintf(local_504,"%s.ufn",param_1);
  iVar1 = FUN_004fa5f0(local_504,1);
  iVar2 = FUN_004fa5f0(param_3,0);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) - param_2;
    *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) - param_2;
    FUN_004f03d0(iVar1,param_2,*(undefined4 *)(param_2 + 8));
    *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) + param_2;
    *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + param_2;
    for (iVar3 = FUN_004f6b40(iVar2); iVar3 != 0; iVar3 = iVar3 - iVar4) {
      iVar4 = iVar3;
      if (0x3ff < iVar3) {
        iVar4 = 0x400;
      }
      iVar4 = FUN_004fb550(iVar2,local_404,iVar4);
      FUN_004f03d0(iVar1,local_404,iVar4);
    }
    FUN_004f99e0(iVar2);
    FUN_004f99e0(iVar1);
  }
  __security_check_cookie(local_4 ^ (uint)local_504);
  return;
}

