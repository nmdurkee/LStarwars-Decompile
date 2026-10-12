/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x469ff0; label: FUN_00469ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00469ff0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_008792e0 = PTR_s_GizForce_00758b47_1_007f8d70;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_008792e0;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_008792f4 = 0;
  _DAT_00879300 = 0;
  _DAT_00879320 = 0;
  _DAT_00879328 = 0;
  DAT_008792e4 = &DAT_007516c0;
  _DAT_008792e8 = 0xb0;
  _DAT_008792ec = FUN_00467ab0;
  _DAT_008792f0 = FUN_00467ad0;
  _DAT_008792f8 = FUN_00468b50;
  _DAT_008792fc = FUN_00467670;
  _DAT_00879304 = FUN_00467b30;
  _DAT_00879308 = FUN_00467b40;
  _DAT_0087930c = FUN_00467c30;
  _DAT_00879310 = FUN_00467ca0;
  _DAT_00879314 = FUN_00468780;
  _DAT_00879318 = FUN_00468840;
  _DAT_0087931c = FUN_00467170;
  _DAT_00879324 = FUN_004671b0;
  _DAT_0087932c = &LAB_00467fe0;
  _DAT_00879330 = FUN_004680b0;
  _DAT_00879334 = &LAB_00468460;
  _DAT_00879338 = FUN_00467cb0;
  _DAT_0087933c = FUN_00467cd0;
  _DAT_00879340 = FUN_00467d50;
  _DAT_00879344 = FUN_004688c0;
  _DAT_00879348 = FUN_00467040;
  _DAT_0087934c = FUN_00466c20;
  _DAT_00879350 = FUN_00466f30;
  _DAT_00879354 = FUN_00466f90;
  DAT_007f8cc4 = param_1;
  return &DAT_008792e0;
}

