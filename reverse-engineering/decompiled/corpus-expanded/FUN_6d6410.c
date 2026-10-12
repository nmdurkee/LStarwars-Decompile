/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6410; label: FUN_006d6410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d6410(void)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f3bb0();
  fVar1 = (float10)FUN_005be630(0x40000000,(float)fVar1 * 4.0);
  _DAT_029758fc = (float)((float10)1 - (float10)1 / fVar1);
  return;
}

