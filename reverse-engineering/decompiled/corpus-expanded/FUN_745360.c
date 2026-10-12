/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745360; label: FUN_00745360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745360(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) + 1;
  return;
}

