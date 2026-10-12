/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e4ee0; label: FUN_005e4ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005e4ee0(int param_1)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = (int *)FUN_00547580(DAT_00973ff8,0);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if ((piVar1[1] == unaff_EDI) && (*(int *)(*piVar1 + 0x1f0) == param_1)) break;
    piVar1 = (int *)FUN_00547580(DAT_00973ff8,piVar1);
  }
  return *piVar1;
}

