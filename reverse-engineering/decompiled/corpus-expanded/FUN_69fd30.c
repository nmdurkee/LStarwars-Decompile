/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69fd30; label: FUN_0069fd30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069fd30(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  iVar1 = 0;
  if (in_ECX != 0) {
    for (uVar2 = in_ECX - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

