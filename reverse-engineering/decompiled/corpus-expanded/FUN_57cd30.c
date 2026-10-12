/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cd30; label: FUN_0057cd30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0057cd30(int param_1,int param_2,int param_3)

{
  if (param_1 == 0) {
    if (param_2 == 0) {
      return 0;
    }
    if (param_3 == 0) {
      return 0;
    }
    param_1 = FUN_0057c970(param_2,param_3);
    if (param_1 == 0) {
      return 0;
    }
  }
  if (7 < DAT_00951c7c) {
    return 0;
  }
  (&DAT_00951c0c)[DAT_00951c7c] = param_1;
  DAT_00951c7c = DAT_00951c7c + 1;
  return param_1;
}

