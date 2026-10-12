/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x743980; label: FUN_00743980
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00743980(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  float10 fVar3;
  undefined4 local_70;
  float local_6c;
  double local_68;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [12];
  undefined4 local_3c;
  undefined4 local_2c;
  undefined4 local_1c;
  
  if (-1 < *(short *)(param_1 + 0x130)) {
    local_54 = 0x3f000000;
    local_50 = 0x3f000000;
    local_4c = 0x3f000000;
    if ((_DAT_0297d684 & 1) == 0) {
      _DAT_0297d684 = _DAT_0297d684 | 1;
    }
    if (DAT_0082b168 != DAT_0297dc00) {
      _DAT_0082b164 = *(float *)(param_2 + 0x60) * _DAT_0082b0f0 + _DAT_0082b164;
    }
    if ((DAT_0297d680 != param_2) || (DAT_0082b168 != DAT_0297dc00)) {
      FUN_005b5b20(local_48,&DAT_009736e8);
      FUN_005b4a50(local_48,&local_54);
      local_1c = 0;
      local_2c = 0;
      local_3c = 0;
      local_70 = 0x11;
      local_6c = *(float *)(param_2 + 0x6c) * 0.1;
      FUN_005b9d90(&local_70);
      puVar2 = &DAT_0297d480;
      do {
        fVar3 = (float10)FUN_005b9d90(&local_70);
        local_68 = (double)((fVar3 * (float10)0.4000000059604645 + (float10)0.800000011920929) *
                           (float10)_DAT_0082b164);
        fVar3 = (float10)FUN_005b9d90(&local_70);
        local_60 = (float)(fVar3 * (float10)6.2829999923706055 + (float10)local_68);
        iVar1 = FUN_006e6b90();
        local_60 = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * local_6c * _DAT_0082b160;
        fVar3 = (float10)FUN_005b9d90(&local_70);
        local_68 = (double)((fVar3 * (float10)0.800000011920929 + (float10)0.6000000238418579) *
                           (float10)_DAT_0082b164);
        fVar3 = (float10)FUN_005b9d90(&local_70);
        local_5c = (float)(fVar3 * (float10)5.7170000076293945 + (float10)local_68);
        iVar1 = FUN_006e6b90();
        local_5c = (float)(&DAT_029899a0)[0x4000 - iVar1 >> 1 & 0x7fff] * local_6c * _DAT_0082b160;
        fVar3 = (float10)FUN_005b9d90(&local_70);
        local_68 = (double)((fVar3 * (float10)0.4000000059604645 + (float10)0.699999988079071) *
                           (float10)_DAT_0082b164);
        fVar3 = (float10)FUN_005b9d90(&local_70);
        local_58 = (float)(fVar3 * (float10)6.2829999923706055 + (float10)local_68);
        iVar1 = FUN_006e6b90();
        local_58 = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * local_6c;
        *(float *)(puVar2 + 0xc) = local_60 / _DAT_0082b160;
        FUN_005b3110(puVar2,&local_60,local_48);
        puVar2 = puVar2 + 0x10;
      } while ((int)puVar2 < 0x297d680);
    }
    FUN_00744060(param_1,0x17,0,0x20,&DAT_0297d480);
    DAT_0297d680 = param_2;
    DAT_0082b168 = DAT_0297dc00;
  }
  return;
}

