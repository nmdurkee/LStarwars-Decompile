/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d69a0; label: FUN_005d69a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d69a0(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  fVar1 = _DAT_00964050;
  if (param_3 != 0.0) {
    _DAT_00964050 = param_3 + (_DAT_00964050 - DAT_00973734);
  }
  FUN_005b30a0(&local_50,param_1,&DAT_00963fa0);
  local_44 = _DAT_00963fcc * param_1[2] + *param_1 * _DAT_00963fac + param_1[1] * _DAT_00963fbc +
             _DAT_00963fdc;
  local_40 = _DAT_00964040 * param_1[2] + *param_1 * _DAT_00964020 + param_1[1] * _DAT_00964030 +
             _DAT_00964050;
  local_3c = _DAT_00964044 * param_1[2] + *param_1 * _DAT_00964024 + param_1[1] * _DAT_00964034 +
             _DAT_00964054;
  FUN_005b30a0(&local_30,param_2,&DAT_00964070);
  local_24 = _DAT_0096409c * param_2[2] + *param_2 * _DAT_0096407c + param_2[1] * _DAT_0096408c;
  local_20 = _DAT_00964048 * param_2[2] + *param_2 * _DAT_00964028 + param_2[1] * _DAT_00964038;
  local_1c = _DAT_0096404c * param_2[2] + *param_2 * _DAT_0096402c + param_2[1] * _DAT_0096403c;
  _DAT_00964050 = fVar1;
  if ((((-local_30 <= local_50) && (-local_2c <= local_4c)) && (-local_28 <= local_48)) &&
     (((-local_24 <= local_44 && (-local_20 <= local_40)) && (-local_1c <= local_3c)))) {
    if (((local_50 < local_30) || (local_4c < local_2c)) ||
       ((local_48 < local_28 || (local_44 < local_24)))) {
      FUN_005b30a0(&local_50,param_1,&DAT_00963fe0);
      local_44 = _DAT_0096400c * param_1[2] + *param_1 * _DAT_00963fec + param_1[1] * _DAT_00963ffc
                 + _DAT_0096401c;
      FUN_005b30a0(&local_30,param_2,&DAT_009640b0);
      if ((((local_50 < local_30) || (local_4c < local_2c)) || (local_48 < local_28)) ||
         (local_44 <
          _DAT_009640dc * param_2[2] + *param_2 * _DAT_009640bc + param_2[1] * _DAT_009640cc +
          _DAT_009640ec)) {
        return 2;
      }
    }
    return 1;
  }
  return 0;
}

