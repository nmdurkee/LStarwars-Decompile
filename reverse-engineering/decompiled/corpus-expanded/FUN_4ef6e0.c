/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef6e0; label: FUN_004ef6e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef6e0(void *param_1,byte param_2,int param_3)

{
  _memset(param_1,(uint)param_2,param_3 << 4);
  return;
}

