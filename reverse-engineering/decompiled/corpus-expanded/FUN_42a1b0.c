/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a1b0; label: FUN_0042a1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042a1b0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
     ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x40) != 0)) {
    if (param_1 == DAT_0087a7e0) {
      if ((uint)DAT_0086e4e2 < (uint)*(byte *)(param_1 + 0x6c) * 2) {
        return 0;
      }
    }
    else if ((DAT_0086e4e2 < *(byte *)(param_1 + 0x6c)) &&
            (iVar1 = FUN_00474d50(param_1), iVar1 != 0)) {
      return 0;
    }
  }
  return 1;
}

