/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0ef0; label: FUN_005b0ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005b0ef0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095e398;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095e3a0 = 0;
  _DAT_0095e3ac = 0;
  _DAT_0095e3b0 = 0;
  _DAT_0095e3b4 = 0;
  _DAT_0095e3b8 = 0;
  _DAT_0095e3d0 = 0;
  _DAT_0095e3d4 = 0;
  _DAT_0095e3d8 = 0;
  _DAT_0095e3e4 = 0;
  _DAT_0095e3e8 = 0;
  _DAT_0095e3ec = 0;
  _DAT_0095e3f0 = 0;
  _DAT_0095e3f4 = 0;
  _DAT_0095e3f8 = 0;
  _DAT_0095e408 = 0;
  _DAT_0095e40c = 0;
  DAT_0095e398 = "MiniCut";
  DAT_0095e39c = &DAT_007516c0;
  _DAT_0095e3a4 = FUN_005b0900;
  _DAT_0095e3a8 = FUN_005b0960;
  _DAT_0095e3bc = FUN_005b08f0;
  _DAT_0095e3c0 = FUN_005b0920;
  _DAT_0095e3c4 = FUN_005b0aa0;
  _DAT_0095e3c8 = FUN_005b09b0;
  _DAT_0095e3cc = FUN_005b0db0;
  _DAT_0095e3dc = FUN_005b09c0;
  _DAT_0095e3e0 = FUN_005b09e0;
  _DAT_0095e3fc = FUN_005b0df0;
  _DAT_0095e400 = &LAB_005b0ac0;
  _DAT_0095e404 = FUN_005b07a0;
  return &DAT_0095e398;
}

