/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5ed300; label: FUN_005ed300
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ed300(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  if (param_4 == 0) {
    if (*(float *)(param_3 + 100) == 0.0) {
      fVar1 = *(float *)(param_3 + 0x4c);
    }
    else {
      fVar1 = *(float *)(param_3 + 100);
    }
    fVar1 = fVar1 - _DAT_0080b9c8;
    if (*(float *)(param_3 + 0x60) == 0.0) {
      fVar2 = *(float *)(param_3 + 0x48);
    }
    else {
      fVar2 = *(float *)(param_3 + 0x60);
    }
    iVar6 = FUN_006e6b90();
    fVar3 = (float)(&DAT_029899a0)[iVar6 + 0x4000 >> 1 & 0x7fff];
    fVar4 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
    fVar5 = *(float *)(param_3 + 0x44) * (fVar3 / fVar4) * _DAT_00963e40;
    _memset(&DAT_0080b8c8,0,0x40);
    _DAT_0080b8dc = _DAT_00963e44 * (fVar3 / fVar4);
    _DAT_0080b8f0 = (fVar2 + fVar1) / (fVar1 - fVar2);
    _DAT_0080b8f4 = 0x3f800000;
    _DAT_0080b900 = (fVar1 * -2.0 * fVar2) / (fVar1 - fVar2);
    _DAT_0080b904 = 0;
    _DAT_0080b8c8 = fVar5;
  }
  FUN_005c0500(param_1,param_2,&DAT_0080b8c8);
  return;
}

