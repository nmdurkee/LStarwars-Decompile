/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bdd50; label: FUN_005bdd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

