/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a3c0; label: FUN_0057a3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0057a3c0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_00951bb8 == 0) {
    return -1;
  }
  if (DAT_00803b78 == -1) {
    return -1;
  }
  iVar3 = DAT_00803b7c - DAT_00803b78;
  iVar2 = DAT_00803b78;
  while( true ) {
    if (iVar3 + 1 <= iVar2) {
      return -1;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(DAT_00951bb8 + 4 + iVar2 * 8),param_1);
    if (iVar1 == 0) break;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

