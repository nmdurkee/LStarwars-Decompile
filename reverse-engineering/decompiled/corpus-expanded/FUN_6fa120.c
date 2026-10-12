/* Ghidra pseudocode, not original source.
 * ev_77aeb2367ed99f8a41c442dae19643b7a9da5543c353c848e7914996f03c14a2
 * Entry: 0x6fa120; label: __except2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __except2
   
   Library: Visual Studio 2005 Release */

void __except2(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  undefined1 local_90 [48];
  undefined8 local_60;
  uint local_50;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)local_90;
  iVar1 = __handle_exc(param_1,&param_5,param_6);
  if (iVar1 == 0) {
    local_60 = param_4;
    local_50 = local_50 & 0xffffffe3 | 3;
    __raise_exc_ex(local_90,&param_6,param_1,param_2,&param_3,&param_5,0);
  }
  iVar1 = __errcode(param_1);
  if ((DAT_0082a740 == 0) && (iVar1 != 0)) {
    __umatherr(iVar1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    __set_errno_from_matherr(iVar1);
    __ctrlfp();
  }
  __security_check_cookie(local_14 ^ (uint)local_90);
  return;
}

