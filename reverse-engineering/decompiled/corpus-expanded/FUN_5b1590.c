/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1590; label: FUN_005b1590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1590(void)

{
  int in_ECX;
  
  if (DAT_0095e410 != 0) {
    DAT_0095e410 = DAT_0095e410 + -1;
    return;
  }
  if ((*(byte *)(*(int *)(in_ECX + 4) + 0x10) & 2) != 0) {
    FUN_00565c00(1);
    return;
  }
  FUN_005658e0();
  return;
}

