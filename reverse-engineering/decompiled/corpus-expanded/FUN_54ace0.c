/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54ace0; label: FUN_0054ace0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054ace0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00574e20();
  if ((((param_2 == 0) || ((&DAT_009253d4)[param_1 * 0x60] != '\0')) &&
      ((*(byte *)((&DAT_009253b0)[param_1 * 0x18] + 0x80) & 4) == 0)) &&
     (((DAT_008037f8 == -1 || (iVar1 != DAT_008037f8)) &&
      ((DAT_00803804 == -1 || (iVar1 != DAT_00803804)))))) {
    return 1;
  }
  return 0;
}

