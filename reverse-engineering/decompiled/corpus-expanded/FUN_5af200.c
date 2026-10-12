/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af200; label: FUN_005af200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005af200(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if ((param_3 & 1) == 0) {
      FUN_005d90c0(iVar1,param_2 == 0);
      return 1;
    }
    if ((param_2 == 0) || (param_2 == (*(byte *)(iVar1 + 0x1c) & 1))) {
      return 1;
    }
  }
  return 0;
}

