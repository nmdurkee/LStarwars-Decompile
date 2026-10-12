/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1490; label: FUN_005b1490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1490(void)

{
  int in_ECX;
  
  if (0 < DAT_0095e410) {
    DAT_0095e410 = DAT_0095e410 + -1;
  }
  if (((*(byte *)(*(int *)(in_ECX + 4) + 0x10) & 2) != 0) && (DAT_0095e410 == 0)) {
    DAT_00950748 = 1;
  }
  return;
}

