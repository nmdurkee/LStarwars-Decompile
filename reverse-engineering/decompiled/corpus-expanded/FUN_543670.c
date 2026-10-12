/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x543670; label: FUN_00543670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00543670(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  FUN_006dd8c0(&DAT_009243f0);
  pcVar1 = (char *)0x9243ef;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"SavedGames",0xb);
  iVar3 = 0;
  do {
    pcVar1 = &DAT_009243f0 + iVar3;
    (&DAT_009244f0)[iVar3] = *pcVar1;
    iVar3 = iVar3 + 1;
  } while (*pcVar1 != '\0');
  FUN_004ff930();
  return;
}

