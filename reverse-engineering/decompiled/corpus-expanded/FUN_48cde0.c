/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48cde0; label: FUN_0048cde0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048cde0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00951b74 + 0x114) = (float)fVar1;
  return;
}

