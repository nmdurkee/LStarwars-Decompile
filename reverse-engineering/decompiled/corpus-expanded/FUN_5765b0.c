/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x5765b0; label: FUN_005765b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005765b0(void)

{
  float fVar1;
  
  if (DAT_009514b8 != 0) {
    if ((*(float *)(DAT_009514b8 + 8) != 0.0) &&
       (fVar1 = *(float *)(DAT_009514b8 + 8) - 0.5, _DAT_009514c8 < fVar1)) {
      _DAT_009514c8 = fVar1;
      *(undefined4 *)(DAT_009514b8 + 0x18) = 0;
      return;
    }
    *(undefined4 *)(DAT_009514b8 + 0x18) = 0;
  }
  return;
}

