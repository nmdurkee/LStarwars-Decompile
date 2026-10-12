/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ea9d0; label: FUN_005ea9d0
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

