/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571700; label: FUN_00571700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00571700(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00950f80 = PTR_s_GizmoPickup_00803430;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00950f80;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00950f94 = 0;
  _DAT_00950fa0 = 0;
  _DAT_00950fb8 = 0;
  _DAT_00950fc0 = 0;
  _DAT_00950fc8 = 0;
  _DAT_00950fcc = 0;
  _DAT_00950fd0 = 0;
  _DAT_00950fd4 = 0;
  _DAT_00950ff4 = 0;
  DAT_00950f84 = &DAT_007516c0;
  _DAT_00950f88 = 0x100;
  _DAT_00950f8c = &LAB_0056f5d0;
  _DAT_00950f90 = FUN_0056f5f0;
  _DAT_00950f98 = FUN_005716c0;
  _DAT_00950f9c = FUN_0056f590;
  _DAT_00950fa4 = FUN_0056f650;
  _DAT_00950fa8 = FUN_0056f660;
  _DAT_00950fac = FUN_0056f680;
  _DAT_00950fb0 = FUN_0056f690;
  _DAT_00950fb4 = FUN_0056f6a0;
  _DAT_00950fbc = FUN_0056fb50;
  _DAT_00950fc4 = FUN_0056fe90;
  _DAT_00950fd8 = &LAB_0056f7f0;
  _DAT_00950fdc = FUN_0056f810;
  _DAT_00950fe0 = FUN_0056f860;
  _DAT_00950fe4 = &LAB_0056fcb0;
  _DAT_00950fe8 = FUN_0056fa60;
  _DAT_00950fec = FUN_0056fea0;
  _DAT_00950ff0 = FUN_00570120;
  DAT_008033a4 = param_1;
  return &DAT_00950f80;
}

