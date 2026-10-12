/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631d90; label: FUN_00631d90
 */

void FUN_00631d90(int *param_1)

{
  int *piVar1;
  
  param_1[9] = 0;
  if ((*param_1 != 0) && (param_1[2] != 0)) {
    if ((DAT_029131cc != 0) && (piVar1 = *(int **)(DAT_029131cc + 4), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x104))(piVar1,0,0);
    }
    FUN_00633350(param_1[2]);
    param_1[2] = 0;
    param_1[9] = 1;
  }
  return;
}

