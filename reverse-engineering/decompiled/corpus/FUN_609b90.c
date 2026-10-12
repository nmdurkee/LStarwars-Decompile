/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x609b90; label: FUN_00609b90
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

