/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x485120; label: FUN_00485120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00485120(undefined4 param_1,int param_2)

{
  float fVar1;
  
  if (*(float *)(param_2 + 0x1c) < *(float *)(param_2 + 0x18)) {
    *(undefined4 *)(param_2 + 0x18) = 0;
    DAT_0087a1a0 = DAT_0087a1a0 + 1;
    _DAT_0087a1a8 = 0x3f000000;
    _DAT_0087a1ac = 1.0;
    return 1;
  }
  fVar1 = *(float *)(param_2 + 0x1c) - _DAT_007fa4b8;
  if ((fVar1 - _DAT_007fa4bc < *(float *)(param_2 + 0x18)) &&
     (*(float *)(param_2 + 0x18) < fVar1 != (*(float *)(param_2 + 0x18) == fVar1))) {
    _DAT_0087a1ac =
         ((*(float *)(param_2 + 0x1c) - *(float *)(param_2 + 0x18)) - _DAT_007fa4b8) / _DAT_007fa4bc
    ;
    return 0;
  }
  return 0;
}

