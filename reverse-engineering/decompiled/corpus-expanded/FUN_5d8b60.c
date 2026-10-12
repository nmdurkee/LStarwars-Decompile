/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d8b60; label: FUN_005d8b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d8b60(float *param_1,float *param_2,float param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  fVar1 = param_2[2] * _DAT_0096e548 + *param_2 * _DAT_0096e540 + param_2[1] * _DAT_0096e544;
  fVar2 = param_1[2] * _DAT_00971888 + *param_1 * _DAT_00971880 + param_1[1] * _DAT_00971884 +
          _DAT_0097188c;
  param_3 = fVar2 - param_3;
  fVar2 = fVar2 - DAT_00973730;
  if ((param_3 <= fVar1) && (-fVar1 <= fVar2)) {
    FUN_005c1aa0(&local_30);
    FUN_005b30a0(&local_20,param_2,&DAT_00971ac0);
    if ((local_30 <= local_20) &&
       (((local_2c <= local_1c && (local_28 <= local_18)) && (local_24 <= local_14)))) {
      if ((((local_30 <= -local_20) && (local_2c <= -local_1c)) && (local_28 <= -local_18)) &&
         (local_24 <= -local_14)) {
        if (param_4 == 0) {
          if (-fVar1 < param_3) {
            return 2;
          }
          if (fVar2 < fVar1) {
            return 2;
          }
        }
        return 1;
      }
      if (param_4 != 0) {
        FUN_005c1aa0(&local_30);
        FUN_005b30a0(&local_20,param_2,&DAT_00971660);
        if (local_20 < local_30) {
          return 0;
        }
        if (local_1c < local_2c) {
          return 0;
        }
        if (local_18 < local_28) {
          return 0;
        }
        if (local_14 < local_24) {
          return 0;
        }
        if (local_30 <= -local_20) {
          if (-local_1c < local_2c) {
            return 2;
          }
          if ((local_28 <= -local_18) && (local_24 <= -local_14)) {
            return 1;
          }
        }
      }
      return 2;
    }
  }
  return 0;
}

