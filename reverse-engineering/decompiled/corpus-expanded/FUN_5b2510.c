/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b2510; label: FUN_005b2510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b2510(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4,
                 code *param_5,undefined4 param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_208;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_208;
  DAT_0095e428 = 0;
  FUN_004f1f10(local_204,"movies\\");
  if (DAT_009250b0 == 0) {
    pcVar2 = "ntsc\\";
  }
  else {
    pcVar2 = "pal\\";
  }
  FUN_004f1e80(local_204,pcVar2);
  FUN_004f1e80(local_204,param_1);
  FUN_004f1f10(local_104,local_204);
  FUN_004f1e80(local_104,&DAT_00763f9c);
  FUN_004f1e80(local_204,&DAT_0075eab4);
  if (DAT_02962034 == 0) {
    FUN_00698ed0();
    FUN_00698e70();
  }
  _DAT_0095e424 = 0;
  DAT_0095e42c = param_5;
  local_208 = param_6;
  _DAT_0095e434 = param_4;
  if (param_5 == (code *)0x0) {
    DAT_0095e42c = FUN_0054b440;
  }
  if ((param_2 != 0) && (param_3 != (undefined4 *)0x0)) {
    iVar1 = FUN_00630e00(2,local_204,3,4,2,7,FUN_005b2470,10,0,0xe,&local_208,8,param_2,*param_3,5,
                         local_104,1);
    if (iVar1 != 0) {
      __security_check_cookie(local_4 ^ (uint)&local_208);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_208);
  return;
}

