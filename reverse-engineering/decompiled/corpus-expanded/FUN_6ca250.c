/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca250; label: FUN_006ca250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ca250(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  if (in_ECX[1] == 0) {
    FUN_004f1f40(param_1,&DAT_00763b90,param_2);
  }
  else {
    iVar1 = FUN_006c8760(2,DAT_02973ac4,local_84,0x80);
    if (iVar1 == 0) {
      FUN_004f1f10(local_84,"NoName");
    }
    _sprintf(param_1,"%s.%s",*(undefined4 *)*in_ECX,local_84);
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

