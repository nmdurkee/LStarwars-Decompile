/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6ead85; label: FUN_006ead85
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ead85(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_006ead72();
  *puVar1 = param_1;
  uVar2 = FUN_006ead24(param_1);
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = uVar2;
  return;
}

