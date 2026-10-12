/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5c10; label: FUN_006c5c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_006c5c10(undefined4 *param_1)

{
  int iVar1;
  
  while( true ) {
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = FUN_0061f030();
    if (param_1[2] == iVar1) break;
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}

