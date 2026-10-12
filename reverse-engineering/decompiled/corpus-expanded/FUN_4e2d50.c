/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e2d50; label: FUN_004e2d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e2d50(void)

{
  int iVar1;
  
  if (DAT_0087aa20 == '\x01') {
    DAT_0087aa20 = '\x02';
    iVar1 = FUN_005cfac0(&DAT_0087aad8);
    if (iVar1 != 0) {
      FUN_005cfc00(&DAT_0087aad8,1);
    }
    iVar1 = FUN_005cfac0(&DAT_0087aae4);
    if (iVar1 != 0) {
      FUN_005cfc00(&DAT_0087aae4,1);
    }
  }
  return;
}

