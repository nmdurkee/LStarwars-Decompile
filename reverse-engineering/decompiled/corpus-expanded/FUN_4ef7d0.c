/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef7d0; label: FUN_004ef7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef7d0(int param_1)

{
  uint *in_EAX;
  
  if (param_1 != 0) {
    *in_EAX = *in_EAX | 0x80000000;
    return;
  }
  *in_EAX = *in_EAX & 0x7fffffff;
  return;
}

