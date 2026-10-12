/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcad0; label: FUN_005fcad0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fcad0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  
  uVar1 = FUN_005d6180();
  _DAT_00986908 = *param_2;
  _DAT_0098690c = param_2[1];
  _DAT_00986910 = param_2[2];
  _DAT_00986914 = *param_4;
  _DAT_00986918 = param_4[1];
  _DAT_0098691c = param_4[2];
  _DAT_00986920 = *param_6;
  _DAT_00986924 = param_6[1];
  _DAT_00986928 = param_6[2];
  FUN_005b3200(&DAT_009868e4,param_1,uVar1);
  FUN_005b3200(&DAT_009868f0,param_3,uVar1);
  FUN_005b3200(&DAT_009868fc,param_5,uVar1);
  FUN_005b3b30(&DAT_009868e4,&DAT_009868e4);
  FUN_005b3b30(&DAT_009868f0,&DAT_009868f0);
  FUN_005b3b30(&DAT_009868fc,&DAT_009868fc);
  _DAT_009868c0 = _DAT_009868c0 + 1;
  _DAT_009868c4 = _DAT_009868c4 + 1;
  _DAT_009868d4 = 0;
  return;
}

