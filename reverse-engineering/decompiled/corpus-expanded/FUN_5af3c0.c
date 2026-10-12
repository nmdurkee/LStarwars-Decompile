/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af3c0; label: FUN_005af3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005af3c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0095e104 = PTR_s_portal__00805f94;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095e100;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095e108 = 0;
  _DAT_0095e114 = 0;
  _DAT_0095e118 = 0;
  _DAT_0095e11c = 0;
  _DAT_0095e120 = 0;
  _DAT_0095e13c = 0;
  _DAT_0095e140 = 0;
  _DAT_0095e144 = 0;
  _DAT_0095e148 = 0;
  _DAT_0095e14c = 0;
  _DAT_0095e150 = 0;
  _DAT_0095e154 = 0;
  _DAT_0095e168 = 0;
  _DAT_0095e16c = 0;
  _DAT_0095e170 = 0;
  _DAT_0095e174 = 0;
  DAT_0095e100 = "Portal";
  _DAT_0095e10c = FUN_005af0e0;
  _DAT_0095e110 = FUN_005af100;
  _DAT_0095e124 = FUN_005af160;
  _DAT_0095e128 = FUN_005af1a0;
  _DAT_0095e12c = FUN_005af1d0;
  _DAT_0095e130 = FUN_005af1c0;
  _DAT_0095e134 = FUN_005af1e0;
  _DAT_0095e138 = FUN_005af200;
  _DAT_0095e158 = FUN_005af300;
  _DAT_0095e15c = FUN_005af320;
  _DAT_0095e160 = FUN_005af330;
  _DAT_0095e164 = FUN_005af250;
  _DAT_0095e0e8 = param_1;
  return &DAT_0095e100;
}

