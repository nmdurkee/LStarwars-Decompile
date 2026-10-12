/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c8030; label: FUN_005c8030
 */

void FUN_005c8030(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int extraout_EDX;
  int local_6c;
  float local_54;
  undefined1 local_50 [76];
  
  iVar5 = FUN_006e6b90();
  fVar2 = ((float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] * *(float *)(param_1 + 0x48)) /
          (float)(&DAT_029899a0)[iVar5 + 0x4000 >> 1 & 0x7fff];
  fVar3 = fVar2 / *(float *)(param_1 + 0x44);
  fVar4 = *(float *)(param_1 + 0x4c) / *(float *)(param_1 + 0x48);
  fVar1 = *(float *)(param_1 + 0x48);
  *param_2 = -fVar3;
  param_2[1] = -fVar2;
  param_2[2] = fVar1;
  param_2[3] = 1.0;
  fVar1 = *(float *)(param_1 + 0x48);
  param_2[4] = -fVar3;
  param_2[5] = fVar2;
  param_2[6] = fVar1;
  param_2[7] = 1.0;
  fVar1 = *(float *)(param_1 + 0x48);
  param_2[8] = fVar3;
  param_2[9] = fVar2;
  param_2[10] = fVar1;
  param_2[0xb] = 1.0;
  fVar1 = *(float *)(param_1 + 0x48);
  param_2[0xc] = fVar3;
  param_2[0xd] = -fVar2;
  param_2[0xe] = fVar1;
  param_2[0xf] = 1.0;
  param_2[0x10] = fVar4 * *param_2;
  param_2[0x11] = fVar4 * param_2[1];
  param_2[0x12] = param_2[2] * fVar4;
  param_2[0x13] = local_54;
  param_2[0x14] = fVar4 * param_2[4];
  param_2[0x15] = param_2[5] * fVar4;
  param_2[0x16] = param_2[6] * fVar4;
  param_2[0x17] = local_54;
  param_2[0x18] = param_2[8] * fVar4;
  param_2[0x19] = param_2[9] * fVar4;
  param_2[0x1a] = param_2[10] * fVar4;
  param_2[0x1b] = local_54;
  param_2[0x1c] = param_2[0xc] * fVar4;
  param_2[0x1d] = param_2[0xd] * fVar4;
  param_2[0x1e] = fVar4 * param_2[0xe];
  param_2[0x1f] = local_54;
  FUN_005c19d0();
  local_6c = 8;
  iVar5 = extraout_EDX;
  do {
    FUN_005b30a0(iVar5,iVar5,local_50);
    iVar5 = iVar5 + 0x10;
    local_6c = local_6c + -1;
  } while (local_6c != 0);
  FUN_005c7fa0();
  return;
}

