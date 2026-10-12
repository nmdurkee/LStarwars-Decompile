/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c0a0; label: FUN_0055c0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055c0a0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_0093b290 != 0) && (iVar2 = 0, 0 < DAT_0093b294)) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(DAT_0093b290 + iVar2 * 4),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0093b294);
  }
  return -1;
}

