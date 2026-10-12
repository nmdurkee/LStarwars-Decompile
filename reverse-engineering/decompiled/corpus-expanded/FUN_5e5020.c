/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5020; label: FUN_005e5020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005e5020(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00547580(DAT_00973ff8,0);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      FUN_005e4f30(param_2,(undefined4 *)(param_1 + 0x1f0),1);
      iVar2 = FUN_005e4ee0(*(undefined4 *)(param_1 + 0x1f0));
      return iVar2;
    }
    if ((piVar1[1] == param_2) && (*(int *)(*piVar1 + 0x1f0) == *(int *)(param_1 + 0x1f0))) break;
    piVar1 = (int *)FUN_00547580(DAT_00973ff8,piVar1);
  }
  return *piVar1;
}

