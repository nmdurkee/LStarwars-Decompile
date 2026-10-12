/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bdd50; label: FUN_005bdd50
 */

void FUN_005bdd50(void)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = 0;
  do {
    fVar2 = (float10)FUN_006e8e80();
    (&DAT_029899a0)[iVar1] = (float)fVar2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x8000);
  return;
}

