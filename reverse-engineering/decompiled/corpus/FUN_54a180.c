/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a180; label: FUN_0054a180
 */

void FUN_0054a180(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    DAT_009253a0 = param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      FUN_00578da0(*piVar2,&param_1);
      *(undefined2 *)(piVar2 + 1) = param_1._0_2_;
      piVar2 = piVar2 + 4;
      iVar1 = *piVar2;
    }
  }
  return;
}

