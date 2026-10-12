/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554d40; label: FUN_00554d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char FUN_00554d40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_005a0f10(*(undefined4 *)(param_1 + 0x68));
  if (iVar1 != 0) {
    return '\0';
  }
  return (*(int *)(*(int *)(param_1 + 0x68) + 0xc) == 2) + '\x01';
}

