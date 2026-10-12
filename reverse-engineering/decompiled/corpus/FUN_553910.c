/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x553910; label: FUN_00553910
 */

int FUN_00553910(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if (DAT_00802850 == -1) {
    return 0;
  }
  iVar2 = 0;
  while (((iVar1 = (&DAT_0093d7f0)[iVar2], iVar1 == 0 || (*(char *)(iVar1 + 0x7b5) != DAT_00802850))
         || (*(int *)(iVar1 + 0x798) != unaff_ESI))) {
    iVar2 = iVar2 + 1;
    if (7 < iVar2) {
      return 0;
    }
  }
  return iVar1;
}

