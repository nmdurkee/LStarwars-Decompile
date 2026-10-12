/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x586ad0; label: FUN_00586ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586ad0(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = FUN_004f7fb0();
  if (iVar2 != 0) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(unaff_ESI + 0x510));
    *param_1 = uVar1;
  }
  return;
}

