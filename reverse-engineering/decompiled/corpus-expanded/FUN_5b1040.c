/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1040; label: FUN_005b1040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1040(void)

{
  int iVar1;
  
  if ((((DAT_00951be0 == 0) && (iVar1 = *(int *)(PTR_DAT_00802c54 + 0x128), iVar1 != 0)) &&
      ((*(byte *)(iVar1 + 100) & 0xe0) == 0)) && (iVar1 != DAT_00951b88)) {
    FUN_00681f40("WipeScreen",0);
  }
  return;
}

