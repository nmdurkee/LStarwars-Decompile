/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d5270; label: FUN_005d5270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005d5270(void)

{
  int iVar1;
  float10 extraout_ST0;
  float10 fVar2;
  
  iVar1 = FUN_006e6b90();
  fVar2 = (float10)iVar1;
  if (fVar2 < extraout_ST0) {
    fVar2 = (float10)(float)(fVar2 + (float10)1.0);
  }
  return fVar2;
}

