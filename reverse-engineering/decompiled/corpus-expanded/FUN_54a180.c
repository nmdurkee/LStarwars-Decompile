/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x54a180; label: FUN_0054a180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

