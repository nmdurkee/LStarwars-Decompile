/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69dfa0; label: FUN_0069dfa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069dfa0(void)

{
  int iVar1;
  int unaff_ESI;
  
  do {
    if (*(int *)(unaff_ESI + 0x58) == 4) {
      iVar1 = FUN_006a2db0(unaff_ESI + 0x1e0,0);
      if (iVar1 != 0) {
        return 0;
      }
    }
    iVar1 = FUN_0069c090(0,1,0);
  } while ((-1 < iVar1) || (iVar1 == -3));
  return iVar1;
}

