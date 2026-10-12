/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52c6d0; label: FUN_0052c6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052c6d0(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_8c;
  undefined4 local_88;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_8c;
  local_8c = *param_3;
  uVar2 = 0;
  local_88 = param_4;
  if (DAT_00801c68 != 0) {
    _sprintf(local_84,"%s\\ai.pak",param_1);
    iVar1 = FUN_004fa690(local_84);
    if (0 < iVar1) {
      local_8c = *param_3 - (iVar1 + 0x10U & 0xfffffff0);
      uVar2 = FUN_004fd9f0(local_84,&local_8c,*param_3,0x10);
    }
  }
  FUN_0052c470(uVar2,param_1,param_2,&local_8c,local_88);
  __security_check_cookie(local_4 ^ (uint)&local_8c);
  return;
}

