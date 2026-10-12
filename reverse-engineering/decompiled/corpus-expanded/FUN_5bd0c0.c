/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bd0c0; label: FUN_005bd0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bd0c0(void)

{
  int iVar1;
  
  iVar1 = FUN_006e6b90();
  if (DAT_0095e5d8 <= iVar1) {
    iVar1 = DAT_0095e5d8 + -1;
  }
  if (DAT_0095e5dc == 0) {
    return (float10)0;
  }
  return (float10)*(float *)(DAT_0095e5dc + 4 + iVar1 * 0xc);
}

