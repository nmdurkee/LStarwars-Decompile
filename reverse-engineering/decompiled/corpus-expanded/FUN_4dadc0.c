/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dadc0; label: FUN_004dadc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004dadc0(void)

{
  if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b090) && (DAT_00882a70 == 1)) &&
      (182.0 < *(float *)(PTR_DAT_008021b4 + 0x2c))) &&
     (*(float *)(DAT_00882a6c + 0xb004) <
      ((*(float *)(DAT_00882a6c + 0xb00c) - 2.8) + *(float *)(PTR_DAT_008021b4 + 0x2c)) - 182.0)) {
    return 1;
  }
  return 0;
}

