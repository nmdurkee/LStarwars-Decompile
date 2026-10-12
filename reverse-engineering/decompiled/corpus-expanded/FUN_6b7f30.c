/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7f30; label: FUN_006b7f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b7f30(void)

{
  int in_EAX;
  undefined4 *in_ECX;
  
  *(undefined4 *)(in_EAX + 0x30) = *in_ECX;
  *(undefined4 *)(in_EAX + 0x34) = in_ECX[1];
  *(undefined4 *)(in_EAX + 0x38) = in_ECX[2];
  *(undefined4 *)(in_EAX + 0x3c) = in_ECX[3];
  *(undefined4 *)(in_EAX + 0x3c) = 0x3f800000;
  return;
}

