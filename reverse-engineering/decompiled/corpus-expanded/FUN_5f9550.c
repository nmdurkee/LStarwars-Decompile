/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f9550; label: FUN_005f9550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f9550(float param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 local_80;
  float local_7c;
  double local_78;
  float local_6c [3];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_48 [12];
  undefined4 local_3c;
  undefined4 local_2c;
  undefined4 local_1c;
  
  local_60 = 0x3f000000;
  local_5c = 0x3f000000;
  local_58 = 0x3f000000;
  if (DAT_02854be4 == 0) {
    DAT_02854be4 = param_3;
  }
  if (DAT_02854be8 != DAT_00924858) {
    _DAT_0080e174 = *(float *)(param_3 + 0x60) * _DAT_0080e170 + _DAT_0080e174;
  }
  if ((DAT_02854be4 != param_3) || (DAT_02854be8 != DAT_00924858)) {
    DAT_02854be8 = DAT_00924858;
    DAT_02854be4 = param_3;
    FUN_005b5b20(local_48,&DAT_009736e8);
    FUN_005b4a50(local_48,&local_60);
    local_1c = 0;
    local_2c = 0;
    local_3c = 0;
    local_80 = 0x11;
    local_7c = *(float *)(param_3 + 0x6c) * param_1;
    FUN_005b9d90(&local_80);
    puVar2 = &DAT_028358ac;
    do {
      fVar4 = (float10)FUN_005b9d90(&local_80);
      local_78 = (double)((fVar4 * (float10)0.4000000059604645 + (float10)0.800000011920929) *
                         (float10)_DAT_0080e174);
      fVar4 = (float10)FUN_005b9d90(&local_80);
      local_6c[0] = (float)(fVar4 * (float10)6.2829999923706055 + (float10)local_78);
      iVar1 = FUN_006e6b90();
      local_6c[0] = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * local_7c;
      local_6c[1] = 0.0;
      fVar4 = (float10)FUN_005b9d90(&local_80);
      local_78 = (double)((fVar4 * (float10)0.4000000059604645 + (float10)0.699999988079071) *
                         (float10)_DAT_0080e174);
      fVar4 = (float10)FUN_005b9d90(&local_80);
      local_6c[2] = (float)(fVar4 * (float10)6.2829999923706055 + (float10)local_78);
      iVar1 = FUN_006e6b90();
      local_6c[2] = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * local_7c;
      FUN_005b3110(&local_54,local_6c,local_48);
      puVar3 = puVar2 + 4;
      puVar2[-1] = local_54;
      *puVar2 = local_50;
      puVar2[1] = 0x3f800000;
      puVar2[2] = local_6c[0];
      puVar2 = puVar3;
    } while ((int)puVar3 < 0x2835aac);
  }
  return;
}

