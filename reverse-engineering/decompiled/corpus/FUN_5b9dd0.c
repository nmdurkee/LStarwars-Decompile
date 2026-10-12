/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b9dd0; label: FUN_005b9dd0
 */

float10 FUN_005b9dd0(void)

{
  DAT_0095e5d4 = DAT_0095e5d4 * 0x19660d + 0x3c6ef35f;
  return (float10)((float)(DAT_0095e5d4 & 0x7fffff | 0x3f800000) - 1.0);
}

