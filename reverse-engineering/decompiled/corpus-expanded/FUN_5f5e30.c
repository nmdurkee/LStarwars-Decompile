/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5e30; label: FUN_005f5e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f5e30(int param_1)

{
  int iVar1;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  FUN_005b5e90(local_40,&DAT_0097ac80);
  FUN_005f28d0(param_1);
  local_80 = 0x3f000000;
  iVar1 = param_1 + 0xc0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0xbf000000;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_54 = 0;
  local_58 = 0x3f000000;
  local_50 = 0x3f000000;
  local_4c = 0x3f000000;
  local_48 = 0x3f000000;
  local_44 = 0x3f800000;
  FUN_005c1240(iVar1,local_40,param_1 + 0x80);
  FUN_005c1240(iVar1,iVar1,&local_80);
  return;
}

