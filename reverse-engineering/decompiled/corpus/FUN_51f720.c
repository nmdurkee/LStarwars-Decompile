/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51f720; label: FUN_0051f720
 */

void FUN_0051f720(float *param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_48;
  float local_40;
  
  iVar4 = 1;
  local_48 = *param_1;
  local_40 = param_2 + param_1[2];
  if (param_7 < 1) {
    return;
  }
  do {
    iVar3 = (iVar4 << 0x10) / param_7;
    fVar2 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * param_2 + *param_1;
    fVar1 = param_1[2] + (float)(&DAT_029899a0)[iVar3 + 0x4000 >> 1 & 0x7fff] * param_2;
    FUN_00512cc0(local_48,param_3,local_40,fVar2,param_3,fVar1,param_5);
    FUN_00512cc0(local_48,param_4,local_40,fVar2,param_4,fVar1,param_5);
    FUN_00512cc0(fVar2,param_3,fVar1,fVar2,param_4,fVar1,param_5);
    iVar4 = iVar4 + 1;
    local_48 = fVar2;
    local_40 = fVar1;
  } while (iVar4 <= param_7);
  return;
}

