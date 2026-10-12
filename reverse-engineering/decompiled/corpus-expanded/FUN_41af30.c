/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41af30; label: FUN_0041af30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0041af30(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0056e160(0x1c);
  if ((iVar1 == 0) && ((param_1 == 0 || (*(float *)(param_1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

