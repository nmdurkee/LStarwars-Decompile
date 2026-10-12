/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x512cc0; label: FUN_00512cc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00512cc0(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,undefined4 param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (_DAT_00922210 <= 0.0) {
    FUN_005dc050(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  fVar1 = DAT_00973720;
  fVar2 = DAT_00973718;
  fVar3 = DAT_0097371c;
  if ((DAT_009238e4 != 0) && ((*(byte *)(DAT_009238e4 + 0x43828) & 2) != 0)) {
    fVar1 = *(float *)(DAT_009238e4 + 0x30);
    fVar2 = *(float *)(DAT_009238e4 + 0x28);
    fVar3 = *(float *)(DAT_009238e4 + 0x2c);
  }
  if ((_DAT_00922210 * _DAT_00922210 <=
       (fVar1 - param_3) * (fVar1 - param_3) +
       (fVar3 - param_2) * (fVar3 - param_2) + (fVar2 - param_1) * (fVar2 - param_1)) &&
     (_DAT_00922210 * _DAT_00922210 <=
      (fVar1 - param_6) * (fVar1 - param_6) +
      (fVar3 - param_5) * (fVar3 - param_5) + (fVar2 - param_4) * (fVar2 - param_4))) {
    return;
  }
  FUN_005dc050(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

