/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4eef20; label: FUN_004eef20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004eef20(void *param_1)

{
  if (DAT_0088ab2c != 0) {
    FUN_004efb00(DAT_0088ab2c,param_1);
    return;
  }
  _free(param_1);
  return;
}

