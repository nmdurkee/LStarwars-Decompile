/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x609b90; label: FUN_00609b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609b90(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x2c);
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_004ef280(*(int *)(param_1 + 0x20),
                 "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x25d);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    if (puVar2[3] != 0) {
      puVar2[3] = 0;
    }
  }
  if ((*(int *)(param_1 + 0x38) != 0) && (*(int *)(*(int *)(param_1 + 0x38) + 0x10) != 0)) {
    FUN_006e5b70();
    return;
  }
  return;
}

