/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e27d0; label: FUN_006e27d0
 */

undefined4 FUN_006e27d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(byte *)(in_ECX + 0x654) & 0x20) != 0) {
    uVar1 = 0x10;
  }
  return uVar1;
}

