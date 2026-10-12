/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b8320; label: FUN_004b8320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8320(float param_1,float param_2,float param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  float local_208;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_208;
  FUN_0054bbc0(param_2,param_5,1,1,local_204);
  if ((param_3 < 0.0 != (param_3 == 0.0)) || (param_2 < param_3)) {
    uVar1 = 0xbf;
  }
  else {
    uVar1 = 0x1f;
  }
  FUN_0050c780(local_204,0,param_1,0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,0xff,uVar1,0,0x80);
  if (param_3 <= 0.0) {
    __security_check_cookie(local_4 ^ (uint)&local_208);
    return;
  }
  FUN_0054bbc0(param_3,param_5,1,1,local_204);
  FUN_004f1f10(local_104,&DAT_00755d74);
  FUN_004f1e80(local_104,local_204);
  FUN_004f1e80(local_104,&DAT_00755d70);
  local_208 = _DAT_007fc37c;
  if (param_4 == 0) {
    local_208 = -_DAT_007fc37c;
  }
  local_208 = local_208 + param_1;
  FUN_0050c780(local_104,0,local_208,0x3f800000,0x3eb33333,0x3eb33333,0x3eb33333,0,0xff,0xff,0xff,
               0x30);
  __security_check_cookie(local_4 ^ (uint)&local_208);
  return;
}

