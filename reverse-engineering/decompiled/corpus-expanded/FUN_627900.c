/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627900; label: FUN_00627900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00627900(undefined4 param_1)

{
  float fVar1;
  
  fVar1 = _DAT_0080f510;
  _DAT_0080f510 = (float)param_1;
  if (DAT_02912e6c != 0) {
    FUN_006242b0(DAT_02912e6c,8);
  }
  return (float10)fVar1;
}

