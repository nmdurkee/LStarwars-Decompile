/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5149a0; label: thunk_FUN_005b9dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 thunk_FUN_005b9dd0(void)

{
  DAT_0095e5d4 = DAT_0095e5d4 * 0x19660d + 0x3c6ef35f;
  return (float10)((float)(DAT_0095e5d4 & 0x7fffff | 0x3f800000) - 1.0);
}

