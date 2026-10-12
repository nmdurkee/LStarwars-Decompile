/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d5500; label: FUN_005d5500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d5500(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float10 fVar7;
  float local_90;
  float local_8c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_50;
  float local_4c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  
  fVar5 = DAT_00973730;
  fVar1 = DAT_00973730 * DAT_00973730;
  fVar2 = DAT_00966378 * DAT_00973730;
  fVar3 = DAT_00973730 * DAT_0097313c;
  fVar6 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1);
  fVar7 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar1);
  FUN_005b44c0(&local_90);
  fVar4 = -fVar5;
  local_90 = (float)((float10)1 / fVar6) * fVar4;
  local_70 = (float)((float10)1 / fVar6) * fVar2;
  local_8c = -local_90;
  local_78 = (float)((float10)1 / fVar7) * fVar4;
  local_68 = (float)((float10)1 / fVar7) * fVar3;
  local_74 = -local_78;
  fVar2 = _DAT_00966270 * fVar5;
  fVar5 = fVar5 * _DAT_0096dce4;
  local_6c = local_70;
  local_64 = local_68;
  fVar6 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1);
  fVar7 = (float10)FUN_005c0240(fVar5 * fVar5 + fVar1);
  FUN_005b44c0(&local_50);
  local_50 = (float)((float10)1 / fVar6) * fVar4;
  local_30 = (float)((float10)1 / fVar6) * fVar2;
  local_4c = -local_50;
  local_38 = (float)((float10)1 / fVar7) * fVar4;
  local_28 = (float)((float10)1 / fVar7) * fVar5;
  local_34 = -local_38;
  local_2c = local_30;
  local_24 = local_28;
  FUN_005c1240(&DAT_00963fa0,&DAT_0080b708,&local_90);
  FUN_005c1240(&DAT_00963fe0,&DAT_0080b708,&local_50);
  _DAT_00964060 = DAT_00973708;
  _DAT_00964064 = DAT_0097370c;
  _DAT_00964068 = DAT_00973710;
  _DAT_00964050 =
       DAT_0097370c * DAT_0097371c + DAT_00973708 * DAT_00973718 + DAT_00973710 * DAT_00973720;
  _DAT_00964054 = -_DAT_00964050 - DAT_00973730;
  _DAT_00964020 = -DAT_00973708;
  _DAT_00964030 = -DAT_0097370c;
  _DAT_00964040 = -DAT_00973710;
  _DAT_00964050 = DAT_00973734 + _DAT_00964050;
  _DAT_00964024 = DAT_00973708;
  _DAT_00964034 = DAT_0097370c;
  _DAT_00964044 = DAT_00973710;
  _DAT_00964028 = ABS(_DAT_00964020);
  _DAT_00964038 = ABS(_DAT_00964030);
  _DAT_00964048 = ABS(_DAT_00964040);
  _DAT_00964058 = ABS(_DAT_00964050);
  _DAT_0096402c = ABS(DAT_00973708);
  _DAT_0096403c = ABS(DAT_0097370c);
  _DAT_0096404c = ABS(DAT_00973710);
  _DAT_0096405c = ABS(_DAT_00964054);
  _DAT_00964070 = DAT_00963fa0 & 0x7fffffff;
  _DAT_00964074 = DAT_00963fa4 & 0x7fffffff;
  _DAT_0096407c = _DAT_00963fac & 0x7fffffff;
  _DAT_00964078 = _DAT_00963fa8 & 0x7fffffff;
  _DAT_0096406c = _DAT_00964054;
  FUN_005c1600();
  FUN_005c1600();
  _DAT_009640a0 = 0;
  _DAT_009640a4 = 0;
  _DAT_009640a8 = 0;
  _DAT_009640ac = 0;
  _DAT_009640b0 = _DAT_00963fe0 & 0x7fffffff;
  _DAT_009640b8 = _DAT_00963fe8 & 0x7fffffff;
  _DAT_009640bc = _DAT_00963fec & 0x7fffffff;
  _DAT_009640b4 = _DAT_00963fe4 & 0x7fffffff;
  FUN_005c1600();
  FUN_005c1600();
  _DAT_009640e0 = 0;
  _DAT_009640e4 = 0;
  _DAT_009640e8 = 0;
  _DAT_009640ec = 0;
  return;
}

