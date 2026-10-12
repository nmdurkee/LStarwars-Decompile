/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621c00; label: FUN_00621c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621c00(int param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  for (; 0 < param_1; param_1 = param_1 + -1) {
    iVar1 = FUN_004f1ff0(PTR_DAT_0080facc);
    iVar2 = FUN_004f1ff0(PTR_DAT_0080fad0);
    puVar3 = PTR_DAT_0080fad0 + iVar2 + 1;
    if (puVar3 < PTR_DAT_0080fac8) {
      PTR_DAT_0080fad0 = puVar3;
      if (DAT_02913050 == 0xd) {
        if (PTR_DAT_0080facc + iVar1 + 1 < PTR_DAT_0080fac8) {
          DAT_02913054 = DAT_02913054 + 1;
          PTR_DAT_0080facc = PTR_DAT_0080facc + iVar1 + 1;
        }
      }
      else {
        DAT_02913050 = DAT_02913050 + 1;
      }
    }
  }
  return;
}

