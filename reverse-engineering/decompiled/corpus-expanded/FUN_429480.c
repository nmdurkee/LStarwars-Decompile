/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429480; label: FUN_00429480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00429480(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0062a6a0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa));
  if ((uVar1 & 4) != 0) {
    if (param_2 != 0) {
      FUN_00681f40();
      return;
    }
    FUN_00681f40("WhipNowt",param_1 + 0x80);
  }
  return;
}

