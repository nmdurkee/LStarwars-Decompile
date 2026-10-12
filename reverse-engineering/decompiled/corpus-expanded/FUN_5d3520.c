/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3520; label: FUN_005d3520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d3520(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = DAT_009738d8; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[1]) {
    FUN_005d3320(*puVar1);
  }
  return;
}

