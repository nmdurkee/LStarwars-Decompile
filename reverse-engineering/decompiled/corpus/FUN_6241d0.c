/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x6241d0; label: FUN_006241d0
 */

void FUN_006241d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    FUN_0061ec10(param_1);
    iVar1 = *param_1;
    while (iVar1 != 0) {
      piVar2 = (int *)*param_1;
      iVar1 = *piVar2;
      (*(code *)piVar2[0x11])(param_1,piVar2);
      *param_1 = iVar1;
    }
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  return;
}

