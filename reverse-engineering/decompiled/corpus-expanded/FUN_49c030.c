/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49c030; label: FUN_0049c030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049c030(void)

{
  int unaff_ESI;
  
  if ((*(char *)(unaff_ESI + 0x7b5) == '=') &&
     (*(float *)(unaff_ESI + 0x784) + 0.5 < *(float *)(unaff_ESI + 0x77c))) {
    FUN_00437770();
    FUN_004364e0();
  }
  return;
}

