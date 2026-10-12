/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x586860; label: FUN_00586860
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

