/* Ghidra pseudocode, not original source.
 * ev_9238a7d4a32c49ce947fe3ed44bc206dac4b982bd913cd0b1074936c5e6922ce
 * Entry: 0x579850; label: FUN_00579850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579850(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  if ((float)fVar1 < 0.0) {
    *(undefined4 *)(DAT_00951b74 + 0xb8) = 0;
    return;
  }
  *(float *)(DAT_00951b74 + 0xb8) = (float)fVar1;
  return;
}

