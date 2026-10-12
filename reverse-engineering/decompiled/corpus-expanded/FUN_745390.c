/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745390; label: FUN_00745390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00745390(void)

{
  int in_EAX;
  int in_EDX;
  
  return -1 < *(short *)(in_EDX + 0x1c + in_EAX * 0xc);
}

