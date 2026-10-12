/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d76e0; label: FUN_004d76e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004d76e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00881c40 = PTR_s_ZipUp_007ffcac;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00881c40;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00881c54 = 0;
  _DAT_00881c60 = 0;
  _DAT_00881c80 = 0;
  _DAT_00881c84 = 0;
  _DAT_00881c88 = 0;
  _DAT_00881c8c = 0;
  _DAT_00881c90 = 0;
  _DAT_00881c94 = 0;
  _DAT_00881cb0 = 0;
  _DAT_00881cb4 = 0;
  DAT_00881c44 = &DAT_007516c0;
  _DAT_00881c48 = 8;
  _DAT_00881c4c = FUN_004d7540;
  _DAT_00881c50 = FUN_004d7560;
  _DAT_00881c58 = FUN_004d6fd0;
  _DAT_00881c5c = FUN_004d71a0;
  _DAT_00881c64 = FUN_004d75d0;
  _DAT_00881c68 = FUN_004d76a0;
  _DAT_00881c6c = FUN_004d76c0;
  _DAT_00881c70 = FUN_004d76d0;
  _DAT_00881c74 = FUN_004d74f0;
  _DAT_00881c78 = FUN_004d5ab0;
  _DAT_00881c7c = &LAB_004d7510;
  _DAT_00881c98 = FUN_004d75e0;
  _DAT_00881c9c = FUN_004d7600;
  _DAT_00881ca0 = FUN_004d7620;
  _DAT_00881ca4 = &LAB_004d5e50;
  _DAT_00881ca8 = FUN_004d5cd0;
  _DAT_00881cac = FUN_004d5b00;
  DAT_007ffc20 = param_1;
  return &DAT_00881c40;
}

