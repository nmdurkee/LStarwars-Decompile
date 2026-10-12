/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cd80; label: FUN_0057cd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0057cd80(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    if ((DAT_00951be8 == 0) && (DAT_00951c7c == 0)) {
      return 0;
    }
  }
  else if (param_1 != DAT_00951be8) {
    iVar1 = 0;
    if (DAT_00951c7c < 1) {
      return 0;
    }
    while (param_1 != (&DAT_00951c0c)[iVar1]) {
      iVar1 = iVar1 + 1;
      if (DAT_00951c7c <= iVar1) {
        return 0;
      }
    }
  }
  return 1;
}

