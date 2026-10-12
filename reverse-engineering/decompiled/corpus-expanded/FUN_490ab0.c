/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490ab0; label: FUN_00490ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00490ab0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x506c)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x5068) + 0x58 + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x5068) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xa0;
    } while (iVar2 < *(int *)(param_3 + 0x506c));
  }
  return;
}

