/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x4666d0; label: FUN_004666d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004666d0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00876e00 = PTR_s_BombGenerator_007f8cb0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00876e00;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00876e14 = 0;
  _DAT_00876e1c = 0;
  _DAT_00876e20 = 0;
  _DAT_00876e38 = 0;
  _DAT_00876e40 = 0;
  _DAT_00876e48 = 0;
  _DAT_00876e4c = 0;
  _DAT_00876e50 = 0;
  _DAT_00876e54 = 0;
  _DAT_00876e70 = 0;
  _DAT_00876e74 = 0;
  DAT_00876e04 = &DAT_007516c0;
  _DAT_00876e08 = 0x18;
  _DAT_00876e0c = FUN_00466500;
  _DAT_00876e10 = FUN_00466520;
  _DAT_00876e18 = FUN_00466330;
  _DAT_00876e24 = FUN_00466580;
  _DAT_00876e28 = FUN_00466590;
  _DAT_00876e2c = FUN_004665a0;
  _DAT_00876e30 = FUN_004665b0;
  _DAT_00876e34 = FUN_00465f60;
  _DAT_00876e3c = FUN_00465fb0;
  _DAT_00876e44 = FUN_00465ff0;
  _DAT_00876e58 = FUN_004665c0;
  _DAT_00876e5c = FUN_004665e0;
  _DAT_00876e60 = FUN_00466650;
  _DAT_00876e64 = FUN_00466060;
  _DAT_00876e68 = FUN_00465ea0;
  _DAT_00876e6c = FUN_00465e00;
  DAT_007f8c44 = param_1;
  return &DAT_00876e00;
}

