/* Ghidra analysis pseudocode, not original source.
 * ev_0bf9b7e593526bfec203cc134385061e8cfbfb74a64816bf5716f75cb05b36af
 * Entry: 0x6fa066; label: __except1
 */

/* Library Function - Single Match
    __except1
   
   Library: Visual Studio 2005 Release */

void __except1(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined1 local_90 [64];
  uint local_50;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)local_90;
  iVar1 = __handle_exc(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    local_50 = local_50 & 0xfffffffe;
    __raise_exc_ex(local_90,&param_5,param_1,param_2,&param_3,&param_4,0);
  }
  iVar1 = __errcode(param_1);
  if ((DAT_0082a740 == 0) && (iVar1 != 0)) {
    __umatherr(iVar1,param_2,param_3,0,param_4,param_5);
  }
  else {
    __set_errno_from_matherr(iVar1);
    __ctrlfp();
  }
  __security_check_cookie(local_14 ^ (uint)local_90);
  return;
}

