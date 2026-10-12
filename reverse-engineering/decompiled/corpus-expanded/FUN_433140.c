/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x433140; label: FUN_00433140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00433140(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = &DAT_008766b0;
  do {
    if (*pcVar2 == '\0') {
      return iVar1;
    }
    pcVar2 = pcVar2 + 0x34;
    iVar1 = iVar1 + 1;
  } while ((int)pcVar2 < 0x876780);
  return -1;
}

