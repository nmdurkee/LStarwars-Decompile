/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69ece0; label: FUN_0069ece0
 */

undefined8 FUN_0069ece0(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  uVar2 = *(uint *)(iVar1 + 10);
  return CONCAT44((((uint)*(byte *)(iVar1 + 0xd) << 8 | (uVar2 & 0xffffff) >> 0x10) << 8 |
                  (uVar2 & 0xffff) >> 8) << 8 | (uint)*(byte *)(iVar1 + 10),
                  *(undefined4 *)(iVar1 + 6));
}

