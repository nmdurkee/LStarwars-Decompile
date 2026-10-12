/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4eee10; label: FUN_004eee10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004eee10(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    DAT_0088ab28 = (undefined *)0x0;
  }
  else {
    _DAT_0088ab10 = param_1;
    DAT_0088ab28 = &DAT_0088ab10;
    if (param_2 != (undefined4 *)0x0) {
      _DAT_0088ab14 = *param_2;
      return;
    }
  }
  return;
}

