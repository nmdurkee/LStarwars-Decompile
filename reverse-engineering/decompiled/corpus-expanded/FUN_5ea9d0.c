/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea9d0; label: FUN_005ea9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ea9d0(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  uint local_4bc;
  undefined1 local_4b8 [1204];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4bc;
  FUN_004f8f10(local_4b8,param_1,&DAT_007654bc,0x400,&DAT_00761694);
  local_4bc = *param_2 + 0x1f & 0xffffffe0;
  *param_2 = local_4bc;
  iVar1 = FUN_004fd730(local_4b8,param_2,&param_3);
  if (iVar1 == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_4bc);
    return;
  }
  FUN_005ea980(&local_4bc,param_2,param_3);
  __security_check_cookie(local_4 ^ (uint)&local_4bc);
  return;
}

