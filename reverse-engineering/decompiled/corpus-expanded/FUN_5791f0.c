/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x5791f0; label: FUN_005791f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005791f0(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  if (fVar1 < 0.001) {
    *(undefined4 *)(DAT_00951b74 + 0x88) = 0x3a83126f;
    return;
  }
  if (1.0 < fVar1) {
    *(undefined4 *)(DAT_00951b74 + 0x88) = 0x3f800000;
    return;
  }
  *(float *)(DAT_00951b74 + 0x88) = fVar1;
  return;
}

