/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x470e10; label: FUN_00470e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00470e10(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = *(int *)(param_1 + 0x46ec);
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x2810) = *(undefined4 *)(iVar1 + 0x48c);
      *(undefined4 *)(param_2 + 0x2814) = *(undefined4 *)(iVar1 + 0x484);
      *(undefined4 *)(param_2 + 0x2818) = *(undefined4 *)(iVar1 + 0x494);
      return;
    }
    *(undefined4 *)(param_2 + 0x2814) = 0x49f42400;
  }
  return;
}

