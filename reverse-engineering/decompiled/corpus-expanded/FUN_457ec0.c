/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x457ec0; label: FUN_00457ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00457ec0(void)

{
  float fVar1;
  float local_8;
  
  if (DAT_009514b8 == 0) {
    return (float10)0;
  }
  local_8 = 1.0;
  if (((0.0 < *(float *)(DAT_009514b8 + 8)) &&
      (fVar1 = *(float *)(DAT_009514b8 + 8) - 0.5, fVar1 < _DAT_009514c8 != (fVar1 == _DAT_009514c8)
      )) && (local_8 = 1.0 - (_DAT_009514c8 - fVar1) / (*(float *)(DAT_009514b8 + 8) - fVar1),
            local_8 <= 0.0)) {
    return (float10)(_DAT_009514cc * 0.0);
  }
  return (float10)(_DAT_009514cc * local_8);
}

