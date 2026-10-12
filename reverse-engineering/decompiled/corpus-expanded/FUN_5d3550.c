/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3550; label: FUN_005d3550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_005d3550(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = FUN_004f8b10(param_1[6],param_2);
    if (iVar1 == 0) break;
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}

