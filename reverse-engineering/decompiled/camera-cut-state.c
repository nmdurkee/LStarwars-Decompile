/* Ghidra pseudocode; not original source. ev_a15cfc0c75286367d728e200eb91ac6d7c67b3da56f05fa63365a2aee7c5bdc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577880(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,
                 undefined4 param_10)

{
  _DAT_009514f0 = 2;
  _DAT_009514f2 = 0xc;
  _DAT_009514f8 = &DAT_009518fc;
  _DAT_009514fc = param_3;
  if (param_1 != (undefined4 *)0x0) {
    _DAT_009518fc = *param_1;
    _DAT_00951900 = param_1[1];
    _DAT_00951904 = param_1[2];
  }
  if (param_2 != (undefined4 *)0x0) {
    _DAT_00951908 = *param_2;
    _DAT_0095190c = param_2[1];
    _DAT_00951910 = param_2[2];
  }
  FUN_00577790(&DAT_009514f0,param_4,param_5,param_6,param_7,param_10,0);
  if ((param_2 != (undefined4 *)0x0) && (param_8 != 0)) {
    DAT_00951920 = param_2;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_9 != 0)) {
    DAT_00951924 = param_1;
  }
  return;
}

