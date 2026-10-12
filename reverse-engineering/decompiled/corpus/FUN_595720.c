/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x595720; label: FUN_00595720
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595720(float param_1)

{
  float *pfVar1;
  float *pfVar2;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  param_1 = param_1 * 0.5;
  if (param_1 == 1.0) {
    pfVar2 = &DAT_00805038;
    pfVar1 = &DAT_00805080;
  }
  else {
    pfVar2 = &local_24;
    local_24 = DAT_00805038 * param_1;
    pfVar1 = &local_30;
    local_20 = DAT_0080503c * param_1;
    local_1c = DAT_00805040 * param_1;
    local_18 = DAT_00805044 * param_1;
    local_14 = DAT_00805048 * param_1;
    local_10 = DAT_0080504c * param_1;
    local_c = DAT_00805050 * param_1;
    local_8 = DAT_00805054 * param_1;
    local_4 = DAT_00805058 * param_1;
    local_30 = DAT_00805080 * param_1;
    local_2c = DAT_00805084 * param_1;
    local_28 = param_1 * DAT_00805088;
  }
  FUN_00595110(&DAT_0080505c,pfVar2 + 3);
  _DAT_009716e8 = *pfVar1;
  _DAT_009716ec = pfVar1[1];
  _DAT_009716f0 = pfVar1[2];
  FUN_005fca90(pfVar1);
  return;
}

