/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x540340; label: FUN_00540340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00540340(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_029838fc + 0x130) = (float)fVar1;
  return;
}

