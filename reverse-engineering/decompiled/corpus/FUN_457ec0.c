/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x457ec0; label: FUN_00457ec0
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

