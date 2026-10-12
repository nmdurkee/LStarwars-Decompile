/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f3f50; label: FUN_004f3f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f3f50(undefined4 param_1,char *param_2)

{
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  _vsprintf(local_104,param_2,&stack0x0000000c);
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d1060(DAT_009738b8,param_1);
  FUN_005d0fe0(DAT_009738b8,0x3f333333,0x3f333333);
  FUN_005f35e0(DAT_009738b8,0x140,DAT_00917848 * 8,0x10,local_104);
  FUN_005d08c0();
  FUN_005d0a70();
  DAT_00917848 = DAT_00917848 + 0x14;
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

