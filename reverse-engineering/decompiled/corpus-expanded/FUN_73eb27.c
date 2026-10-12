/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x73eb27; label: FUN_0073eb27
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0073eb27(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 < 0x80000000)) {
    uVar1 = FUN_007158bd();
    return uVar1;
  }
  return 0x80070057;
}

