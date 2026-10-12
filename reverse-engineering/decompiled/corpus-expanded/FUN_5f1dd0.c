/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f1dd0; label: FUN_005f1dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f1dd0(int *param_1,int param_2)

{
  int iVar1;
  void *_Dst;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_400;
  undefined4 local_3f0;
  uint local_2d8;
  uint local_25c;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_1f8;
  undefined4 local_1e8;
  uint local_d0;
  uint local_54;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_414;
  thunk_FUN_0060ddc0(param_1);
  DAT_00971590 = param_2;
  _Dst = (void *)(*param_1 + 0xfU & 0xfffffff0);
  DAT_0096e560 = _Dst;
  *param_1 = (*param_1 + 0xfU & 0xfffffff0) + param_2 * 0x2c4;
  _memset(_Dst,0,param_2 * 0x2c4);
  DAT_0095e670 = FUN_005e4b20(1);
  iVar1 = FUN_005e4b20(0);
  DAT_0096d8f0 = iVar1;
  _memset(&local_414,0,0x208);
  local_2d8 = local_2d8 | 0x40101;
  local_3f0 = 0x3f800000;
  local_25c = local_25c | 0x1000;
  local_414 = 0x1000;
  local_410 = 0;
  local_400 = 0xffffffff;
  _memset(&local_20c,0,0x208);
  local_54 = local_54 | 0x1000;
  local_1e8 = 0x3f800000;
  local_d0 = local_d0 | 0x101;
  local_20c = 0x1000;
  local_208 = 0;
  local_1f8 = 0xffffffff;
  FUN_00601230(iVar1,&local_414);
  FUN_00601230(DAT_0095e670,&local_20c);
  iVar1 = DAT_0096d8f0;
  FUN_00601030(DAT_0096d8f0);
  *(short *)(iVar1 + 0x2c0) = *(short *)(iVar1 + 0x2c0) + 1;
  iVar1 = DAT_0095e670;
  FUN_00601030(DAT_0095e670);
  *(short *)(iVar1 + 0x2c0) = *(short *)(iVar1 + 0x2c0) + 1;
  __security_check_cookie(local_4 ^ (uint)&local_414);
  return;
}

