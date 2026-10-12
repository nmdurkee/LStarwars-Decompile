/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604ba0; label: FUN_00604ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00604ba0(int param_1,byte param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)((uint)param_2 * 0x50 + *(int *)(param_1 + 0x184));
  if (*(byte *)(puVar2 + 0x11) == 0xff) {
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_4 = *puVar2;
      puVar2 = puVar2 + 1;
      param_4 = param_4 + 1;
    }
    return;
  }
  FUN_005c0500(param_4,puVar2,(uint)*(byte *)(puVar2 + 0x11) * 0x40 + param_3);
  return;
}

