/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e5960; label: FUN_005e5960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5960(void)

{
  int *piVar1;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))();
    (**(code **)(*piVar1 + 8))();
    *unaff_EDI = 0;
  }
  return;
}

