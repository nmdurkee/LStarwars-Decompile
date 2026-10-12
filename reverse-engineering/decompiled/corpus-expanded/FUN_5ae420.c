/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae420; label: FUN_005ae420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_005ae420(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return "AtEnd";
  }
  if (param_2 != 1) {
    return (char *)0x0;
  }
  return "NotAtStart";
}

