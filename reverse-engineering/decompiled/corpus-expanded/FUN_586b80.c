/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x586b80; label: FUN_00586b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586b80(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(DAT_00954404 + 0xe0);
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    *puVar3 = uVar1;
  }
  return;
}

