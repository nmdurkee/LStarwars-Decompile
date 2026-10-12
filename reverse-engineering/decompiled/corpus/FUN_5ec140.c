/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ec140; label: FUN_005ec140
 */

void FUN_005ec140(float *param_1,float param_2,undefined4 param_3,float param_4,int param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  float local_28;
  float local_24;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x7000;
  do {
    iVar6 = local_14;
    if (3 < local_18) {
      iVar6 = local_10 + 0x1000;
    }
    fVar4 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * param_2;
    if (local_18 < 3) {
      fVar2 = (float)(&DAT_029899a0)[local_14 + 0x1000 >> 1 & 0x7fff];
    }
    else {
      fVar2 = (float)(&DAT_029899a0)[local_10 >> 1 & 0x7fff];
    }
    fVar2 = param_2 * fVar2;
    fVar7 = (float10)FUN_005c0240(param_2 * param_2 - fVar4 * fVar4);
    local_28 = (float)(fVar7 * (float10)param_4);
    fVar7 = (float10)FUN_005c0240(param_2 * param_2 - fVar2 * fVar2);
    local_24 = (float)(fVar7 * (float10)param_4);
    if (4 < local_18) {
      local_28 = -local_28;
    }
    if (3 < local_18) {
      local_24 = -local_24;
    }
    iVar6 = 0x4000;
    local_28 = local_28 + param_1[1];
    fVar3 = param_1[1];
    do {
      uVar5 = iVar6 + -0x4000 >> 1 & 0x7fff;
      pfVar1 = (float *)(&DAT_029899a0 + (iVar6 >> 1 & 0x7fff));
      FUN_005dc050(fVar4 * *pfVar1 + *param_1,local_28,
                   param_1[2] + fVar4 * (float)(&DAT_029899a0)[uVar5],fVar2 * *pfVar1 + *param_1,
                   local_24 + fVar3,param_1[2] + fVar2 * (float)(&DAT_029899a0)[uVar5],param_3);
      iVar6 = iVar6 + param_5;
      FUN_005dc050(fVar4 * *pfVar1 + *param_1,local_28,
                   (float)(&DAT_029899a0)[uVar5] * fVar4 + param_1[2],
                   (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * fVar4 + *param_1,local_28,
                   param_1[2] + fVar4 * (float)(&DAT_029899a0)[iVar6 + -0x4000 >> 1 & 0x7fff],
                   param_3);
    } while (iVar6 + -0x4000 < 0x10000);
    local_18 = local_18 + 1;
    local_14 = local_14 + 0x1000;
    local_10 = local_10 + -0x1000;
  } while (-0x1000 < local_10);
  return;
}

