/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b16e0; label: FUN_005b16e0
 */

void FUN_005b16e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00633440(0x24,1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00633550(4);
    *puVar1 = &PTR_LAB_00763f4c;
    DAT_0095e418 = puVar1;
    return;
  }
  DAT_0095e418 = (undefined4 *)0x0;
  return;
}

