/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1570; label: FUN_005b1570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1570(void)

{
  int in_ECX;
  
  if ((*(byte *)(*(int *)(in_ECX + 4) + 0x10) & 2) != 0) {
    DAT_00950748 = 1;
  }
  return;
}

