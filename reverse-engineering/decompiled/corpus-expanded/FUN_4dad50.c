/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dad50; label: FUN_004dad50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004dad50(void)

{
  if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b094) && (DAT_00882a70 == 3)) &&
      (195.0 < *(float *)(PTR_DAT_008021b4 + 0x2c))) &&
     (*(float *)(DAT_00882a6c + 0xb004) <
      ((*(float *)(DAT_00882a6c + 0xb00c) - 2.8) + *(float *)(PTR_DAT_008021b4 + 0x2c)) - 195.0)) {
    return 1;
  }
  return 0;
}

