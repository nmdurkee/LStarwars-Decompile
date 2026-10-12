/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e2370; label: FUN_004e2370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004e2370(void)

{
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b110) && (PTR_DAT_008021b4[1] == '\x15')) {
    return 1;
  }
  return 0;
}

