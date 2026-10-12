/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x5149a0; label: thunk_FUN_005b9dd0
 */

float10 thunk_FUN_005b9dd0(void)

{
  DAT_0095e5d4 = DAT_0095e5d4 * 0x19660d + 0x3c6ef35f;
  return (float10)((float)(DAT_0095e5d4 & 0x7fffff | 0x3f800000) - 1.0);
}

