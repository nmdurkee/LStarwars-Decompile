/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b6f70; label: FUN_006b6f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b6f70(float param_1)

{
  uint uVar1;
  
  uVar1 = (uint)ROUND(param_1 * -8.0 - 0.5);
  if ((int)uVar1 < 0) {
    return (float10)1.0;
  }
  if (0x45f < (int)uVar1) {
    return (float10)0.0;
  }
  return (float10)(*(float *)(&DAT_0081f8d0 + (uVar1 & 0x1f) * 4) *
                  *(float *)(&DAT_0081f840 + ((int)uVar1 >> 5) * 4));
}

