/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x5595b0; label: FUN_005595b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005595b0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_006218c0();
  if (cVar1 != 0) {
    FUN_006216f0(param_1,(int)cVar1);
    return 1;
  }
  return 0;
}

