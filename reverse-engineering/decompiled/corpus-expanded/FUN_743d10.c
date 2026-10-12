/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x743d10; label: FUN_00743d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00743d10(void)

{
  int *piVar1;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_ESI = 0;
  }
  return;
}

