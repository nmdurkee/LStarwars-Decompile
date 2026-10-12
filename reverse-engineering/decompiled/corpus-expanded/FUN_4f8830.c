/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8830; label: FUN_004f8830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004f8830(void)

{
  float fVar1;
  int *unaff_ESI;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8790();
  while( true ) {
    while( true ) {
      fVar1 = (float)fVar2;
      if (*unaff_ESI != 2) break;
      FUN_004f8420();
      fVar2 = (float10)FUN_004f8790();
      fVar2 = fVar2 * (float10)fVar1;
    }
    if (*unaff_ESI != 3) break;
    FUN_004f8420();
    fVar2 = (float10)FUN_004f8790();
    fVar2 = (float10)fVar1 / fVar2;
  }
  return (float10)fVar1;
}

