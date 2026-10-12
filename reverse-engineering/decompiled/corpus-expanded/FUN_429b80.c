/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429b80; label: FUN_00429b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00429b80(int param_1)

{
  undefined4 uVar1;
  
  if (((param_1 != 0) && (*(short *)(param_1 + 0x1064) == DAT_007f18dc)) &&
     ((*(uint *)(param_1 + 0xef0) & 0x200) == 0)) {
    uVar1 = FUN_00547990();
    return uVar1;
  }
  return 0xffffffff;
}

