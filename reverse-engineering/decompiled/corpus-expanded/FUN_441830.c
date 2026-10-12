/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441830; label: FUN_00441830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441830(void)

{
  if ((DAT_0093d810 != 0) &&
     ((*(char *)(DAT_0093d810 + 0x281) != '\0' || (*(char *)(DAT_0093d810 + 0x282) != '\0')))) {
    return (float10)1;
  }
  return (float10)0;
}

