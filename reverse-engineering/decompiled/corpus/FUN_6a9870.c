/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a9870; label: FUN_006a9870
 */

uint FUN_006a9870(void)

{
  uint in_ECX;
  uint uVar1;
  
  uVar1 = in_ECX << 0x10 | in_ECX >> 0x10;
  uVar1 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
  uVar1 = (uVar1 >> 4 ^ uVar1 << 4) & 0xf0f0f0f ^ uVar1 << 4;
  uVar1 = (uVar1 >> 2 ^ uVar1 * 4) & 0x33333333 ^ uVar1 * 4;
  return (uVar1 >> 1 ^ uVar1 * 2) & 0x55555555 ^ uVar1 * 2;
}

