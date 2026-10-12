/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bddd0; label: FUN_004bddd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004bddd0(void)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  iVar1 = *(int *)(iVar1 + 0x128);
  if (((iVar1 != DAT_0087b1e0) && (iVar1 != DAT_0087b244)) &&
     ((iVar1 != DAT_0087b208 || (PTR_DAT_008021b4[1] != '\x04')))) {
    return 0;
  }
  return 1;
}

