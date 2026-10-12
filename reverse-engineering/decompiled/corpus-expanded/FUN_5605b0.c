/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x5605b0; label: FUN_005605b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005605b0(void)

{
  if ((((DAT_00951b7c == DAT_00951b88) || (DAT_0087b71c != 0)) || (DAT_00803784 != DAT_0095121c)) ||
     (DAT_007fac04 == 0)) {
    FUN_0055ffb0(&DAT_0093d858,0xffffffff);
    if ((DAT_0095121c == -1) || ((*(byte *)(DAT_0095121c * 0x9c + 0x7a + DAT_00951354) & 8) == 0)) {
      FUN_0055ffb0(&DAT_00942a04,0xffffffff);
    }
    DAT_00802c68 = 0xffffffff;
  }
  return;
}

