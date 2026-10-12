/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5b0250; label: FUN_005b0250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005b0250(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095e2a8;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095e2b0 = 0;
  _DAT_0095e2bc = 0;
  _DAT_0095e2c0 = 0;
  _DAT_0095e2c4 = 0;
  _DAT_0095e2c8 = 0;
  _DAT_0095e2e0 = 0;
  _DAT_0095e2e4 = 0;
  _DAT_0095e2e8 = 0;
  _DAT_0095e2ec = 0;
  _DAT_0095e2f0 = 0;
  _DAT_0095e2f4 = 0;
  _DAT_0095e2f8 = 0;
  _DAT_0095e2fc = 0;
  _DAT_0095e300 = 0;
  _DAT_0095e304 = 0;
  _DAT_0095e308 = 0;
  _DAT_0095e30c = 0;
  _DAT_0095e314 = 0;
  DAT_00806144 = param_1;
  DAT_0095e2a8 = "GizRandom";
  DAT_0095e2ac = &DAT_00763eb8;
  _DAT_0095e2b4 = FUN_005affd0;
  _DAT_0095e2b8 = FUN_005afff0;
  _DAT_0095e2cc = FUN_005b0060;
  _DAT_0095e2d0 = FUN_005b0070;
  _DAT_0095e2d4 = FUN_005b0090;
  _DAT_0095e2d8 = FUN_005b00a0;
  _DAT_0095e2dc = FUN_005b00b0;
  _DAT_0095e310 = FUN_005b0130;
  return &DAT_0095e2a8;
}

