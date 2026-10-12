/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5b50; label: FUN_006c5b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_006c5b50(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  do {
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = 0;
    if (0 < (int)param_1[0x1c]) {
      piVar2 = param_1 + 5;
      do {
        if (*(int *)(param_2 + 0xc) == *piVar2) {
          return param_1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 3;
      } while (iVar1 < (int)param_1[0x1c]);
    }
    param_1 = (undefined4 *)*param_1;
  } while( true );
}

