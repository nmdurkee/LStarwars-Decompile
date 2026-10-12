/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x442270; label: FUN_00442270
 */

float10 FUN_00442270(void)

{
  uint *puVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0;
  if (0 < DAT_0093d500) {
    puVar1 = (uint *)(DAT_0093d504 + 0x1fc);
    iVar2 = DAT_0093d500;
    do {
      if ((((*puVar1 & 1) != 0) && ((*puVar1 & 0x1000) != 0)) && ((puVar1[-1] & 1) != 0)) {
        local_4 = local_4 + 1;
      }
      puVar1 = puVar1 + 0x436;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return (float10)local_4;
}

