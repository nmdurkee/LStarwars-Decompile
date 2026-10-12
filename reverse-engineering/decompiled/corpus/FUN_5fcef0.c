/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcef0; label: FUN_005fcef0
 */

void FUN_005fcef0(int param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  puVar1 = (undefined4 *)*DAT_009736e0;
  if (*(int *)(param_1 + 0xf4) != 0) {
    *puVar1 = *(undefined4 *)(param_1 + 0xf8);
    *puVar2 = (uint)(puVar1 + 1);
    return;
  }
  *puVar1 = 0x3f800000;
  *puVar2 = (uint)(puVar1 + 1);
  return;
}

