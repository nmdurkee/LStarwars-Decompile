/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6af260; label: FUN_006af260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006af260(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)param_1[1] != (void *)0x0) {
      _free((void *)param_1[1]);
    }
    if ((void *)param_1[2] != (void *)0x0) {
      _free((void *)param_1[2]);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

