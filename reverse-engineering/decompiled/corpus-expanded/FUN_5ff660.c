/* Ghidra pseudocode, not original source.
 * ev_84daf39e48317c5610d39db166d0a8d3fb26fedafe51c8456603b097e41224df
 * Entry: 0x5ff660; label: FUN_005ff660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ff660(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  
  DAT_0080e228 = param_1;
  DAT_0080e22c = param_2;
  _DAT_0080e230 = param_3;
  _DAT_0080e234 = param_4;
  _DAT_0080e238 = param_5;
  _DAT_0080e23c = param_6;
  _DAT_0080e240 = param_7;
  _DAT_0080e244 = param_8;
  _DAT_0080e250 = param_5;
  _DAT_0080e254 = param_6;
  fVar1 = (float)DAT_0080e694;
  _DAT_0080e248 = (param_7 - param_5) / fVar1;
  fVar2 = (float)DAT_0080e698;
  _DAT_0080e24c = (param_8 - param_6) / fVar2;
  _DAT_0080e258 = fVar1 / (param_3 - param_1);
  _DAT_0080e25c = fVar2 / (param_4 - param_2);
  param_1 = (fVar1 - param_3) - param_1;
  _DAT_0080e260 = (param_1 + param_1) / fVar1;
  _DAT_0080e264 = (((fVar2 - param_4) - param_2) * -2.0) / fVar2;
  return;
}

