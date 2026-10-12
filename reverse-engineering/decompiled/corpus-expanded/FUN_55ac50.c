/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55ac50; label: FUN_0055ac50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055ac50(void)

{
  int unaff_ESI;
  
  if ((unaff_ESI != 0) && (*(void **)(unaff_ESI + 4) != (void *)0x0)) {
    _memset(*(void **)(unaff_ESI + 4),0,DAT_00802724);
  }
  *(ushort *)(unaff_ESI + 8) = *(ushort *)(unaff_ESI + 8) & 0xfffc;
  return;
}

