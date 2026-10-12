/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fd850; label: FUN_004fd850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

