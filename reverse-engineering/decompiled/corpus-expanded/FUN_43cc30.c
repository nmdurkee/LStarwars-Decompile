/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43cc30; label: FUN_0043cc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043cc30(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    _memset((void *)param_1[1],0,*param_1 * 0xa8);
    iVar2 = 0;
    if (0 < *param_1) {
      iVar1 = 0;
      do {
        FUN_004f1310(param_1 + 2,param_1[1] + iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0xa8;
      } while (iVar2 < *param_1);
    }
  }
  return;
}

