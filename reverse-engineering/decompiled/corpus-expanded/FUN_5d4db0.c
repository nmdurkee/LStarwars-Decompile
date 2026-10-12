/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d4db0; label: FUN_005d4db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d4db0(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  undefined1 local_4;
  
  _DAT_009718c8 = 1;
  if (param_3 < 2.0 == (param_3 == 2.0)) {
    DAT_009718cc = 0xff;
  }
  else {
    local_4 = (undefined1)(int)ROUND(param_3 * 127.0);
    DAT_009718cc = local_4;
  }
  _DAT_009718d0 = param_4;
  DAT_009718f8 = 1;
  _DAT_00971910 = 0;
  _DAT_009718d4 = param_2;
  _DAT_00971920 = 0;
  DAT_009718fc = 0;
  _DAT_00971900 = 0;
  _DAT_00971904 = 0x43340000;
  _DAT_00971908 = param_3;
  _DAT_0097190c = 0x3f800000;
  _DAT_00971914 = param_4;
  _DAT_00971918 = 0;
  _DAT_0097191c = param_2;
  return;
}

