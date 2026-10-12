/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dacd0; label: FUN_004dacd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004dacd0(void)

{
  if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b090) && (DAT_00882a70 == 2)) &&
      (1.0 < *(float *)(DAT_00882a6c + 0xb004))) &&
     (((DAT_00882a78 != 0 && (_DAT_007ffd2c - 15.0 < *(float *)(PTR_DAT_008021b4 + 0x2c))) &&
      (*(float *)(PTR_DAT_008021b4 + 0x2c) <= _DAT_007ffd2c + 5.0)))) {
    return 1;
  }
  return 0;
}

