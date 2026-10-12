/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69df70; label: FUN_0069df70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069df70(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x58);
  while( true ) {
    if (iVar1 == 4) {
      return 0;
    }
    iVar1 = FUN_0069c090(0,1,0);
    if ((iVar1 < 0) && (iVar1 != -3)) break;
    iVar1 = *(int *)(unaff_ESI + 0x58);
  }
  return iVar1;
}

