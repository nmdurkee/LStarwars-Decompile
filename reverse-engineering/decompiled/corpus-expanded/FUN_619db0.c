/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619db0; label: FUN_00619db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619db0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int in_ECX;
  
  if (*(code **)(in_EAX + 0x15c) != (code *)0x0) {
    (**(code **)(in_EAX + 0x15c))(param_1,param_2,*(undefined4 *)(in_ECX + 0x70));
  }
  return;
}

