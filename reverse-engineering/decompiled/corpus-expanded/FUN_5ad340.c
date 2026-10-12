/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad340; label: FUN_005ad340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_005ad340(int *param_1,int param_2)

{
  if (param_2 == 0) {
    return "destroyed";
  }
  if (param_2 != 1) {
    if ((param_2 == 2) && (*param_1 != 0)) {
      _sprintf(&DAT_0095dfd4,"Fired %d Shots",(uint)*(byte *)(*param_1 + 0x131));
      return &DAT_0095dfd4;
    }
    return (char *)0x0;
  }
  return "fired";
}

