/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5280; label: FUN_004f5280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f5280(void)

{
  char in_AL;
  
  if (('/' < in_AL) && (in_AL < ':')) {
    return 1;
  }
  return 0;
}

