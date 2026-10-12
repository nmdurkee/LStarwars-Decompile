/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c22b0; label: FUN_005c22b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c22b0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x005c22c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}

