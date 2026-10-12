/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b80e0; label: FUN_004b80e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b80e0(undefined4 param_1,float param_2,float param_3,int param_4,float param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float fVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_30;
  FUN_0054bb30(param_1,local_24);
  local_28 = _DAT_007fc364 * param_3;
  local_30 = (float)CONCAT22(local_30._2_2_,in_FPUControlWord);
  local_2c = _DAT_007fc2e8 + param_2;
  FUN_0050c780(local_24,0,local_2c,0x3f800000,local_28,local_28,local_28,0,param_6,param_7,param_8,
               (int)ROUND(param_5 * 128.0) & 0xff);
  iVar2 = FUN_006e6b90();
  local_28 = param_3 * _DAT_007fc368 * (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
  if (*(char *)(DAT_007fc374 * 0x10 + 0xe + *(int *)(PTR_DAT_00802c54 + 0x2ac0)) != '\0') {
    local_30 = -(_DAT_00921d00 * 0.5) - _DAT_007fc36c * param_3;
    if (param_4 != 0) {
      _DAT_0087b9ac = local_30;
    }
    FUN_00552c10(local_30,param_2,0x3f800000,local_28,local_28,local_28,0,0,0,
                 *(int *)(PTR_DAT_00802c54 + 0x2ac0) + DAT_007fc374 * 0x10,0,0x3f800000);
  }
  if (*(char *)(DAT_007fc378 * 0x10 + 0xe + *(int *)(PTR_DAT_00802c54 + 0x2ac0)) == '\0') {
    __security_check_cookie(local_4 ^ (uint)&local_30);
    return;
  }
  local_30 = _DAT_00921d00 * 0.5 + _DAT_007fc36c * param_3;
  iVar2 = DAT_007fc378;
  fVar1 = local_30;
  if (param_4 == 0) {
    iVar2 = 0xbb;
    fVar1 = _DAT_0087b9b0;
  }
  _DAT_0087b9b0 = fVar1;
  FUN_00552c10(local_30,param_2,0x3f800000,local_28,local_28,local_28,0,0,0,
               iVar2 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),0,0x3f800000);
  __security_check_cookie(local_4 ^ (uint)&local_30);
  return;
}

