/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x6951f0; label: FUN_006951f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006951f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_02962bac != 0) {
    return 1;
  }
  DAT_02962b50 = 0x7f7fffff;
  DAT_02962b54 = 0x7f7fffff;
  local_24 = param_2;
  DAT_02962b58 = 0x7f7fffff;
  _DAT_02962b5c = 0x7f7fffff;
  _DAT_02962b60 = 0x7f7fffff;
  local_28 = param_1;
  _DAT_02962b64 = 0x7f7fffff;
  _DAT_02962b68 = 0x7f7fffff;
  local_20 = param_3;
  _DAT_02962b6c = 0x7f7fffff;
  local_1c = 0;
  _DAT_02962b70 = 0x7f7fffff;
  local_18 = 0x40;
  _DAT_02962b74 = 0x7f7fffff;
  local_14 = 0;
  _DAT_02962b78 = 0x7f7fffff;
  local_10 = 0x1fff;
  _DAT_02962b7c = 0x7f7fffff;
  local_c = 1;
  _DAT_02962b80 = 0x7f7fffff;
  local_8 = 0;
  _DAT_02962b84 = 0x7f7fffff;
  local_4 = 0;
  _DAT_02962b88 = 0x7f7fffff;
  if (param_4 != 0) {
    puVar2 = &param_4;
    do {
      switch(param_4) {
      case 1:
        local_1c = puVar2[1];
        puVar2 = puVar2 + 1;
        break;
      case 2:
        piVar1 = puVar2 + 1;
        puVar2 = puVar2 + 1;
        local_18 = *piVar1 + 0x10;
        break;
      case 3:
        local_14 = puVar2[1];
        puVar2 = puVar2 + 1;
        break;
      case 4:
        local_10 = puVar2[1];
        puVar2 = puVar2 + 1;
        break;
      case 5:
        local_c = puVar2[1];
        puVar2 = puVar2 + 1;
        break;
      case 6:
        local_8 = puVar2[1];
        puVar2 = puVar2 + 1;
      case 0xb:
        local_4 = puVar2[1];
        puVar2 = puVar2 + 1;
      }
      param_4 = puVar2[1];
      puVar2 = puVar2 + 1;
    } while (param_4 != 0);
  }
  uVar3 = FUN_00697d90(&local_28);
  return uVar3;
}

