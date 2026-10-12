/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45e4f0; label: FUN_0045e4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045e4f0(float param_1,int param_2,float param_3)

{
  float fVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  switch(*(undefined4 *)((int)param_1 + 0x14)) {
  case 0:
    *(undefined4 *)((int)param_1 + 0x14) = 1;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0x3f800000;
    return;
  case 1:
    param_3 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = param_3;
    if (*(float *)((int)param_1 + 0x1c) < param_3 != (*(float *)((int)param_1 + 0x1c) == param_3)) {
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x14) = 2;
      *(undefined4 *)((int)param_1 + 0x1c) = 0x40400000;
      *(undefined4 *)(param_2 + 0x58) = 0;
      _DAT_007f8660 = 5.0;
      return;
    }
    break;
  case 2:
    FUN_00482f10(param_2,(int)*(char *)(param_2 + 0xb8));
    if ((*(byte *)(param_2 + 0xb0) & 4) == 0) {
      param_1 = (*(float *)(param_2 + 0x50) * 100.0) / *(float *)(param_2 + 0x54);
      if (99.0 < param_1) {
        param_1 = 99.0;
      }
    }
    else {
      param_1 = 100.0;
    }
    *(float *)(iVar2 + 0x18) = param_3 + *(float *)(iVar2 + 0x18);
    fVar1 = param_3 * (100.0 / *(float *)(iVar2 + 0x1c)) + *(float *)(param_2 + 0x58);
    *(float *)(param_2 + 0x58) = fVar1;
    if (fVar1 <= param_1) {
      if (_DAT_007f8660 < fVar1 != (_DAT_007f8660 == fVar1)) {
        FUN_00681f40("Status_GoldBarDec",0);
        _DAT_007f8660 = _DAT_007f8660 + 10.0;
      }
    }
    else {
      *(float *)(param_2 + 0x58) = param_1;
    }
    if (*(float *)(iVar2 + 0x1c) < *(float *)(iVar2 + 0x18)) {
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(undefined4 *)(iVar2 + 0x1c) = 0x3f800000;
      if (*(int *)(iVar2 + 0xc) == 2) {
        *(undefined4 *)(iVar2 + 0x14) = 6;
        FUN_00681f40("TrueJedi_NOT",0);
        return;
      }
      *(undefined4 *)(iVar2 + 0x14) = 3;
      FUN_00681f40("TrueJedi_100pc",0);
      return;
    }
    break;
  case 3:
    param_3 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = param_3;
    if (*(float *)((int)param_1 + 0x1c) < param_3 != (*(float *)((int)param_1 + 0x1c) == param_3)) {
      *(undefined4 *)((int)param_1 + 0x14) = 6;
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x1c) = 0x3f800000;
      _DAT_00876df0 = 0;
      return;
    }
    break;
  case 6:
    param_3 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = param_3;
    if (*(float *)((int)param_1 + 0x1c) < param_3 != (*(float *)((int)param_1 + 0x1c) == param_3)) {
      FUN_004838f0(param_2);
    }
  }
  return;
}

