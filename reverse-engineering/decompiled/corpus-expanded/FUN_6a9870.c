/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a9870; label: FUN_006a9870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

