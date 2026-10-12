/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x579300; label: FUN_00579300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579300(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00951b74 + 0xc0) = (float)fVar1;
  return;
}

