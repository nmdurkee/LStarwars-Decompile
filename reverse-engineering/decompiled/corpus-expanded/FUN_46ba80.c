/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46ba80; label: FUN_0046ba80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ba80(float param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar2 = (int)param_1;
  if (*(float *)((int)param_1 + 0x104) != 0.0) {
    if ((*(float *)((int)param_1 + 0xfc) == 0.0) || (*(float *)((int)param_1 + 0x104) == 0.0)) {
      param_1 = 0.0;
    }
    else {
      param_1 = *(float *)((int)param_1 + 0xfc) / *(float *)((int)param_1 + 0x104);
    }
    param_1 = 1.0 - param_1;
    if (0.0 < param_1) {
      pfVar1 = (float *)(iVar2 + 0x30);
      iVar3 = FUN_0055cee0(pfVar1,0,0,0,0,0xffffffff,0xffffffff,99,0,0,0);
      if (iVar3 != 0) {
        fVar4 = (float10)FUN_0054fb40(*(undefined4 *)(iVar2 + 0x84),
                                      (*(float *)(iVar3 + 0x84) - *(float *)(iVar2 + 0x34)) * 3.0,
                                      0x40400000);
        *(float *)(iVar2 + 0x84) = (float)fVar4;
      }
      *pfVar1 = *pfVar1 + _DAT_00925018 * param_1 * *(float *)(iVar2 + 0x80);
      *(float *)(iVar2 + 0x34) =
           *(float *)(iVar2 + 0x84) * param_1 * _DAT_00925018 + *(float *)(iVar2 + 0x34);
      *(float *)(iVar2 + 0x38) =
           param_1 * *(float *)(iVar2 + 0x88) * _DAT_00925018 + *(float *)(iVar2 + 0x38);
      return;
    }
  }
  *(uint *)(iVar2 + 0x144) = *(uint *)(iVar2 + 0x144) | 2;
  if (*(code **)(iVar2 + 0x1c8) == (code *)0x0) {
    return;
  }
  (**(code **)(iVar2 + 0x1c8))(iVar2);
  return;
}

