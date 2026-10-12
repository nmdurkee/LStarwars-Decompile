/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4425e0; label: FUN_004425e0
 */

undefined4 FUN_004425e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,param_2,1);
  iVar1 = FUN_005cfac0(local_c);
  if (iVar1 != 0) {
    uVar2 = FUN_005d0420(local_c);
    return uVar2;
  }
  return 0;
}

