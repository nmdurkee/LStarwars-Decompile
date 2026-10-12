/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x422340; label: FUN_00422340
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00422340(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,
                    undefined4 param_5,float param_6,float param_7,undefined4 param_8,
                    undefined4 param_9,float param_10)

{
  float fVar1;
  uint uVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  FUN_005d0fb0(*(undefined4 *)(in_ECX + 0xa0));
  fVar1 = *(float *)(in_ECX + 0x34) * param_7;
  param_7 = *(float *)(in_ECX + 0x30) * param_6;
  FUN_00420700(*(undefined4 *)(in_ECX + 0xa0),param_7,fVar1,&param_7,&param_6);
  FUN_005d0fe0(*(undefined4 *)(in_ECX + 0xa0),param_7,param_6);
  FUN_005d1530(*(undefined4 *)(in_ECX + 0xa0),param_7,param_6);
  fVar3 = (float10)FUN_005d0e80(*(undefined4 *)(in_ECX + 0xa0));
  fVar4 = (float10)FUN_005d0eb0(*(undefined4 *)(in_ECX + 0xa0));
  fVar1 = _DAT_0085684c * (float)fVar3;
  if (param_10 != 0.0) {
    fVar5 = (float10)FUN_005d0d60(*(undefined4 *)(in_ECX + 0xa0),param_1);
    if (param_10 < (float)fVar5) {
      param_7 = (param_10 * param_7) / (float)fVar5;
    }
  }
  uVar2 = FUN_004208a0(*(undefined4 *)(in_ECX + 0xc),param_8);
  FUN_0050c780(param_1,param_2,((float)fVar4 + param_3) - fVar1,param_4,param_7,param_6,0x3f800000,
               param_5,uVar2,uVar2 >> 8,uVar2 >> 0x10,uVar2 >> 0x18);
  return (float10)(float)fVar3;
}

