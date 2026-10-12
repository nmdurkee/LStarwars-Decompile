/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59da30; label: FUN_0059da30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059da30(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = 0;
  if (*(char *)(unaff_EDI + 2) != '\0') {
    do {
      FUN_0059d9d0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(unaff_EDI + 2));
  }
  return;
}

