/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d6040; label: FUN_004d6040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

ushort FUN_004d6040(void)

{
  int in_EAX;
  
  if (in_EAX == 0) {
    return 0;
  }
  if ((*(ushort *)(in_EAX + 0x68) & 1) == 0) {
    return 1;
  }
  return ~(*(ushort *)(in_EAX + 0x68) >> 8) & 1;
}

