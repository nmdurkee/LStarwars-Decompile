/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3320; label: FUN_005d3320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d3320(undefined4 *param_1)

{
  int iVar1;
  
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    iVar1 = param_1[5];
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = 0;
      *(undefined4 *)(iVar1 + 0x88) = 0;
      *(undefined4 *)(iVar1 + 0xcc) = 0;
      *(undefined4 *)(iVar1 + 0xd0) = 0;
      *(undefined4 *)(iVar1 + 0xd4) = 0;
      *(undefined4 *)(iVar1 + 0xd8) = 0;
      *(undefined4 *)(iVar1 + 0xe4) = 0;
    }
  }
  return;
}

