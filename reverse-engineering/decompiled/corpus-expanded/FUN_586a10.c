/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x586a10; label: FUN_00586a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586a10(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(DAT_00954404 + 0x118);
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (-1 < iVar1) {
      *puVar2 = (char)iVar1;
    }
  }
  return;
}

