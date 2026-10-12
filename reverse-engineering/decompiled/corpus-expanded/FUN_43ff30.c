/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43ff30; label: FUN_0043ff30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0043ff30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00517160(param_1,param_2,0x18);
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    iVar2 = FUN_00517160(param_1,param_2,param_3 * 0xa8);
    piVar1[1] = iVar2;
    if (iVar2 != 0) {
      *piVar1 = param_3;
      FUN_0043cc30(piVar1);
    }
  }
  return piVar1;
}

