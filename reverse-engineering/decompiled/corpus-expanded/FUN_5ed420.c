/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ed420; label: FUN_005ed420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ed420(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

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
    fVar5 = *(float *)(param_3 + 0x44) * _DAT_00963e48;
    _memset(&DAT_0097ba90,0,0x40);
    _DAT_0097baa4 = _DAT_00963e4c * (fVar3 / fVar4);
    _DAT_0097bab8 = (fVar2 + fVar1) / (fVar1 - fVar2);
    _DAT_0097babc = 0x3f800000;
    _DAT_0097bac8 = (fVar1 * -2.0 * fVar2) / (fVar1 - fVar2);
    _DAT_0097ba90 = fVar5 * (fVar3 / fVar4);
  }
  FUN_005c0500(param_1,param_2,&DAT_0097ba90);
  return;
}

