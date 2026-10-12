/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x59a1e0; label: FUN_0059a1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059a1e0(float param_1,float param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined1 auStack_38 [4];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_38;
  iVar3 = DAT_00803b9c;
  if (DAT_00856c08 == 0) {
    iVar3 = DAT_00803ba0;
  }
  if ((iVar3 != -1) && (param_1 < 0.0 == (param_1 == 0.0))) {
    iVar1 = FUN_006e6b90();
    local_34 = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
    local_28 = local_34 * (_DAT_0080525c - _DAT_00805264) + _DAT_00805264;
    local_2c = _DAT_00805268 + (_DAT_00805260 - _DAT_00805268) * local_34;
    iVar1 = FUN_0055f450();
    if (*(char *)(iVar3 * 0x10 + 0xe + *(int *)(iVar1 + 0x2ac0)) != '\0') {
      fVar4 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
      uVar2 = (int)ROUND(fVar4 * (float10)0.25 * (float10)65536.0) & 0xffff;
      local_34 = _DAT_0080526c * param_2;
      local_30 = _DAT_00805270 + local_2c;
      FUN_00552d10(local_28,local_30,0x3f800000,local_34,local_34,local_34,
                   (int)ROUND((float)(&DAT_029899a0)[(int)(uVar2 * 2) >> 1 & 0x7fff] * 1820.0) &
                   0xffff,uVar2,0,*(int *)(iVar1 + 0x2ac0) + iVar3 * 0x10,2);
    }
    _sprintf(local_24,"%i/%i",param_3,param_4);
    local_34 = _DAT_00805274 * param_2;
    local_30 = _DAT_00805278 + local_2c;
    FUN_00511500(local_24,local_28,local_30,0x3f800000,local_34,local_34,local_34,0,0xff,0,0x7f);
    __security_check_cookie(local_4 ^ (uint)auStack_38);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)auStack_38);
  return;
}

