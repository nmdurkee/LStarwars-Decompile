/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7c80; label: FUN_006b7c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006b7c80(int param_1)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX - param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

