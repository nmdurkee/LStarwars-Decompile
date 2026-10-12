/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af100; label: FUN_005af100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005af100(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0x13c), iVar1 != 0)) &&
     (iVar2 = 0, 0 < *(int *)(iVar1 + 0x6c))) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar1 + 0x70) + iVar3;
      if (*(char *)(iVar1 + 0x1a) != '\0') {
        FUN_00559ee0(param_1,param_2,0,iVar1);
      }
      iVar1 = *(int *)(param_3 + 0x13c);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < *(int *)(iVar1 + 0x6c));
  }
  return;
}

