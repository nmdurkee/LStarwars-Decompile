/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a6d0; label: FUN_0057a6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057a6d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_0093d854 == 0) {
    DAT_0093d840 = 1;
    DAT_0093d854 = 1;
  }
  FUN_00575450();
  DAT_00951b80 = param_1;
  DAT_0087b71c = 1;
  DAT_00803d8c = param_2;
  DAT_00951bd8 = param_3;
  if ((DAT_00951364 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)) {
    if (DAT_0093b2a8 != 0) {
      DAT_008059f4 = DAT_00802af4;
      return;
    }
    iVar1 = FUN_0058a900(0);
    if (((iVar1 != 0) && (DAT_00951b80 != 0)) && (DAT_00951b80 == DAT_00951b94)) {
      DAT_008059f8 = (int)*(char *)(iVar1 + 0x12);
    }
  }
  return;
}

