/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b6f00; label: FUN_006b6f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b6f00(float param_1)

{
  int iVar1;
  float fVar2;
  
  fVar2 = param_1 * 64.0 - 32.0;
  iVar1 = (int)ROUND(fVar2 - 0.5);
  return (float10)((fVar2 - (float)iVar1) *
                   (*(float *)(&DAT_0081f6b4 + iVar1 * 4) - *(float *)(&DAT_0081f6b0 + iVar1 * 4)) +
                  *(float *)(&DAT_0081f6b0 + iVar1 * 4));
}

