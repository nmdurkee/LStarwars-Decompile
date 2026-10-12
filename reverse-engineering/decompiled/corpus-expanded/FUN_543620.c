/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x543620; label: FUN_00543620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 * FUN_00543620(void)

{
  char *pcVar1;
  char *pcVar2;
  
  FUN_006dd8c0(&DAT_009243f0);
  pcVar1 = (char *)0x9243ef;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"SavedGames",0xb);
  return &DAT_009243f0;
}

