/* Ghidra pseudocode, not original source.
 * ev_97f4a3b699bb455f9f6d61621fe82dddba0f62005898969e9454d063fd653c3d
 * Entry: 0x586860; label: FUN_00586860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00586860(int param_1)

{
  int iVar1;
  uint uVar2;
  
  *(undefined2 *)(DAT_00954404 + 0xf2) = 0;
  while( true ) {
    iVar1 = FUN_004f7fb0(param_1);
    if (iVar1 == 0) break;
    uVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (uVar2 < 0x10) {
      *(ushort *)(DAT_00954404 + 0xf2) =
           *(ushort *)(DAT_00954404 + 0xf2) | (ushort)(1 << ((byte)uVar2 & 0x1f));
    }
  }
  return;
}

