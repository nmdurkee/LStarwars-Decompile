/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x556f50; label: FUN_00556f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00556f50(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0093b128;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0093b140 = 0;
  _DAT_0093b160 = 0;
  _DAT_0093b168 = 0;
  _DAT_0093b198 = 0;
  _DAT_0093b19c = 0;
  DAT_008025d4 = param_1;
  DAT_0093b128 = "Spinner";
  DAT_0093b12c = &DAT_007516c0;
  _DAT_0093b130 = 0x40;
  _DAT_0093b134 = FUN_00554850;
  _DAT_0093b138 = FUN_00554870;
  _DAT_0093b13c = FUN_005568e0;
  _DAT_0093b144 = FUN_00554630;
  _DAT_0093b148 = FUN_00554840;
  _DAT_0093b14c = FUN_00554900;
  _DAT_0093b150 = FUN_00556170;
  _DAT_0093b154 = FUN_00554920;
  _DAT_0093b158 = FUN_005549d0;
  _DAT_0093b15c = FUN_00555550;
  _DAT_0093b164 = FUN_005555a0;
  _DAT_0093b16c = FUN_00555580;
  _DAT_0093b170 = FUN_005557e0;
  _DAT_0093b174 = FUN_005559c0;
  _DAT_0093b178 = FUN_00555a70;
  _DAT_0093b17c = FUN_00556f40;
  _DAT_0093b180 = FUN_005553a0;
  _DAT_0093b184 = FUN_005553c0;
  _DAT_0093b188 = FUN_005552b0;
  _DAT_0093b18c = FUN_00556ea0;
  _DAT_0093b190 = FUN_00554250;
  _DAT_0093b194 = FUN_00553aa0;
  return &DAT_0093b128;
}

