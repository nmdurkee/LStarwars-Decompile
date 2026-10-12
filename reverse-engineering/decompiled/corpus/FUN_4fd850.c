/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fd850; label: FUN_004fd850
 */

void FUN_004fd850(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  FUN_004fd760(param_1,param_2,local_404,0x400);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

