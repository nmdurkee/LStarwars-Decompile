/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x553910; label: FUN_00553910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

