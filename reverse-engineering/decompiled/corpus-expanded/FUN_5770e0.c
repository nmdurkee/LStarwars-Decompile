/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x5770e0; label: FUN_005770e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005770e0(float param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  float10 fVar4;
  float10 extraout_ST0;
  float10 fVar5;
  float fVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar5 = (float10)0;
  if (((float10)_DAT_009518f0 == fVar5) || ((float10)param_1 == fVar5)) {
    fVar6 = (float)fVar5;
    fVar4 = (float10)fVar6;
  }
  else {
    fVar6 = (float)((float10)_DAT_009518f0 / (float10)param_1);
    fVar4 = (float10)fVar6;
    if (fVar5 <= fVar4) {
      if ((float10)1 < fVar4) {
        fVar6 = (float)(float10)1;
        fVar4 = (float10)fVar6;
      }
    }
    else {
      fVar6 = (float)fVar5;
      fVar4 = (float10)fVar6;
    }
  }
  switch(DAT_00951883) {
  case 1:
    iVar1 = FUN_006e6b90();
    fVar5 = (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] + (float10)1.0;
    break;
  case 2:
    iVar1 = FUN_006e6b90();
    fVar5 = (float10)1 -
            ((float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] + (float10)1) * (float10)0.5;
    break;
  case 3:
    iVar1 = FUN_006e6b90();
    fVar5 = (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
    break;
  case 4:
    fVar5 = (float10)0.5;
    if (fVar5 <= fVar4) {
      if (fVar5 < fVar4) {
        iVar1 = FUN_006e6b90();
        fVar5 = ((float10)1 - (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff]) * extraout_ST0 +
                extraout_ST0;
      }
    }
    else {
      iVar1 = FUN_006e6b90();
      fVar5 = (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * (float10)0.5;
    }
    break;
  default:
    goto switchD_00577164_default;
  }
  fVar6 = (float)fVar5;
  fVar4 = (float10)fVar6;
switchD_00577164_default:
  if (DAT_00951882 == '\0') {
    iVar1 = (uint)DAT_00951898 - (uint)DAT_009518bc;
    if (iVar1 < 0x8001) {
      if (iVar1 < -0x10000) {
        iVar1 = iVar1 + 0x10000;
      }
    }
    else {
      iVar1 = iVar1 + -0x10000;
    }
    iVar2 = (uint)DAT_0095189a - (uint)DAT_009518be;
    if (iVar2 < 0x8001) {
      if (iVar2 < -0x10000) {
        iVar2 = iVar2 + 0x10000;
      }
    }
    else {
      iVar2 = iVar2 + -0x10000;
    }
    iVar3 = (uint)DAT_0095189c - (uint)DAT_009518c0;
    if (iVar3 < 0x8001) {
      if (iVar3 < -0x10000) {
        iVar3 = iVar3 + 0x10000;
      }
    }
    else {
      iVar3 = iVar3 + -0x10000;
    }
    DAT_0095188c = FUN_00550070(DAT_0095188c,
                                (int)ROUND(fVar4 * (float10)iVar1 + (float10)DAT_009518bc) & 0xffff,
                                0x41200000,CONCAT22((short)((uint)iVar1 >> 0x10),in_FPUControlWord),
                                fVar6,iVar2,iVar3);
    DAT_0095188e = FUN_00550070(DAT_0095188e,
                                (int)ROUND((float)DAT_009518be + (float)iVar2 * fVar6) & 0xffff,
                                0x41200000,in_FPUControlWord);
    DAT_00951890 = FUN_00550070(DAT_00951890,
                                (int)ROUND((float)DAT_009518c0 + (float)iVar3 * fVar6) & 0xffff,
                                0x41200000,in_FPUControlWord);
    _DAT_00951888 = _DAT_009518b8 + fVar6 * (_DAT_00951894 - _DAT_009518b8);
  }
  else if (DAT_00951882 == '\x01') {
    DAT_009518e0 = _DAT_00925018 * _DAT_009518ac + DAT_009518e0;
    DAT_009518e4 = _DAT_009518b0 * _DAT_00925018 + DAT_009518e4;
    DAT_009518e8 = _DAT_009518b4 * _DAT_00925018 + DAT_009518e8;
  }
  else if (DAT_00951882 == '\x02') {
    FUN_00550a20(DAT_009518ec,(float)fVar4,&DAT_009518e0,0,0,0);
  }
  _DAT_009518c8 = _DAT_009518c8 - _DAT_009518a0 * _DAT_00925018;
  _DAT_009518cc = _DAT_009518cc - _DAT_009518a4 * _DAT_00925018;
  _DAT_009518d0 = _DAT_009518d0 - _DAT_009518a8 * _DAT_00925018;
  if (DAT_009518c4 != 0) {
    FUN_005b37d0(&local_c,DAT_009518c4,&DAT_009518c8);
    fVar5 = (float10)FUN_0054fad0(_DAT_009518d4,local_c,0x41200000);
    _DAT_009518d4 = (float)fVar5;
    fVar5 = (float10)FUN_0054fad0(_DAT_009518d8,local_8,0x41200000);
    _DAT_009518d8 = (float)fVar5;
    fVar5 = (float10)FUN_0054fad0(_DAT_009518dc,local_4,0x41200000);
    _DAT_009518dc = (float)fVar5;
  }
  return;
}

