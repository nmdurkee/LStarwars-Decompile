/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca530; label: FUN_006ca530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ca530(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  iVar1 = *(int *)(param_2 + 0xc);
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  FUN_006ca110(*(undefined4 *)(param_2 + 100));
  FUN_006ca250(local_84,0x80);
  FUN_0061e530(*(undefined4 *)(iVar1 + 4),local_84);
  FUN_006ba280(local_84);
  __security_check_cookie(local_4 ^ (uint)&local_90);
  return;
}

