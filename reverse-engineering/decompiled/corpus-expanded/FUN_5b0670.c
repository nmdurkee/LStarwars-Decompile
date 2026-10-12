/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0670; label: FUN_005b0670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005b0670(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095e320;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095e328 = 0;
  _DAT_0095e338 = 0;
  _DAT_0095e33c = 0;
  _DAT_0095e340 = 0;
  _DAT_0095e358 = 0;
  _DAT_0095e35c = 0;
  _DAT_0095e360 = 0;
  _DAT_0095e364 = 0;
  _DAT_0095e368 = 0;
  _DAT_0095e36c = 0;
  _DAT_0095e370 = 0;
  _DAT_0095e374 = 0;
  _DAT_0095e378 = 0;
  _DAT_0095e37c = 0;
  _DAT_0095e380 = 0;
  _DAT_0095e384 = 0;
  _DAT_0095e390 = 0;
  _DAT_0095e394 = 0;
  DAT_008061b8 = param_1;
  DAT_0095e320 = "GizTimer";
  DAT_0095e324 = &DAT_007516c0;
  _DAT_0095e32c = FUN_005b0370;
  _DAT_0095e330 = FUN_005b0390;
  _DAT_0095e334 = FUN_005b0400;
  _DAT_0095e344 = FUN_005b0450;
  _DAT_0095e348 = FUN_005b0470;
  _DAT_0095e34c = &LAB_005b0490;
  _DAT_0095e350 = FUN_005b04a0;
  _DAT_0095e354 = FUN_005b04b0;
  _DAT_0095e388 = FUN_005b04f0;
  _DAT_0095e38c = FUN_005b05e0;
  return &DAT_0095e320;
}

