/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6ca250; label: FUN_006ca250
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

