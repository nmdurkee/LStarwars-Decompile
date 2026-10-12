/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x512b00; label: FUN_00512b00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00512b00(float *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_50 [19];
  
  local_70 = *param_1;
  local_6c = param_1[1];
  local_68 = param_1[2];
  local_80 = param_1[9];
  local_7c = param_1[10];
  local_78 = param_1[0xb];
  if (param_3 != (undefined4 *)0x0) {
    if (((uint)param_3 & 0xf) != 0) {
      puVar2 = local_50;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_3;
        param_3 = param_3 + 1;
        puVar2 = puVar2 + 1;
      }
      param_3 = local_50;
    }
    FUN_005b30a0(&local_70,&local_70,param_3);
    FUN_005b30a0(&local_80,&local_80,param_3);
  }
  if (0.0 < _DAT_00922210) {
    local_58 = DAT_00973720;
    local_60 = DAT_00973718;
    local_5c = DAT_0097371c;
    if ((DAT_009238e4 != 0) && ((*(byte *)(DAT_009238e4 + 0x43828) & 2) != 0)) {
      local_58 = *(float *)(DAT_009238e4 + 0x30);
      local_60 = *(float *)(DAT_009238e4 + 0x28);
      local_5c = *(float *)(DAT_009238e4 + 0x2c);
    }
    if ((_DAT_00922210 * _DAT_00922210 <
         (local_58 - local_68) * (local_58 - local_68) +
         (local_5c - local_6c) * (local_5c - local_6c) +
         (local_60 - local_70) * (local_60 - local_70)) &&
       (_DAT_00922210 * _DAT_00922210 <
        (local_58 - local_78) * (local_58 - local_78) +
        (local_5c - local_7c) * (local_5c - local_7c) +
        (local_60 - local_80) * (local_60 - local_80))) {
      return;
    }
  }
  FUN_005dc050(local_70,local_6c,local_68,local_80,local_7c,local_78,param_1[6]);
  return;
}

