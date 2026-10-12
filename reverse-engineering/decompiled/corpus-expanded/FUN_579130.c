/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x579130; label: FUN_00579130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579130(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  if (fVar1 < 0.1) {
    *(undefined4 *)(DAT_00951b74 + 0x84) = 0x3dcccccd;
    return;
  }
  if (50.0 < fVar1) {
    *(undefined4 *)(DAT_00951b74 + 0x84) = 0x42480000;
    return;
  }
  *(float *)(DAT_00951b74 + 0x84) = fVar1;
  return;
}

