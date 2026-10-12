/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcf60; label: FUN_005fcf60
 */

void FUN_005fcf60(int param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  *(undefined4 *)*DAT_009736e0 = *(undefined4 *)(param_1 + 0x16c);
  *puVar2 = *puVar2 + 4;
  if (*(int *)(param_1 + 0x16c) != 0) {
    *(undefined4 *)*puVar2 = *(undefined4 *)(param_1 + 0x178);
    *puVar2 = *puVar2 + 4;
    puVar1 = (undefined4 *)*puVar2;
    *puVar1 = *(undefined4 *)(param_1 + 0x170);
    *puVar2 = (uint)(puVar1 + 1);
    puVar1[1] = *(undefined4 *)(param_1 + 0x174);
    *puVar2 = (uint)(puVar1 + 2);
    puVar1[2] = *(undefined4 *)(param_1 + 0x17c);
    *puVar2 = (uint)(puVar1 + 3);
  }
  return;
}

