/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x586910; label: FUN_00586910
 */

void FUN_00586910(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(iVar3 + unaff_EDI) = 0xff;
    iVar1 = FUN_004f7fb0(param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
      if (uVar2 < 0x10) {
        *(char *)(iVar3 + unaff_EDI) = (char)uVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return;
}

