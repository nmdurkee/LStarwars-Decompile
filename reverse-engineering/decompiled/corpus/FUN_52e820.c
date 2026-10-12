/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52e820; label: FUN_0052e820
 */

void FUN_0052e820(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  int local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_98;
  local_90 = param_1;
  local_8c = param_4;
  local_98 = *param_2;
  uVar2 = 0;
  local_94 = param_6;
  local_88 = param_8;
  if (DAT_00801c68 != 0) {
    _sprintf(local_84,"%sLevels\\%s\\%s\\ai.pak",PTR_DAT_00801c70,param_5,param_7);
    iVar1 = FUN_004fa690(local_84);
    if (0 < iVar1) {
      local_98 = *param_2 - (iVar1 + 0x10U & 0xfffffff0);
      uVar2 = FUN_004fd9f0(local_84,&local_98,*param_2,0x10);
    }
  }
  FUN_0052dc60(uVar2,local_90,param_2,param_3,local_94,param_7,local_88);
  __security_check_cookie(local_4 ^ (uint)&local_98);
  return;
}

