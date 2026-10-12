/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x741860; label: FUN_00741860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00741860(uint *param_1,uint param_2,int param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (param_2 - 8) + param_3 * 8;
  if (param_2 <= uVar4) {
    do {
      iVar3 = ((int)(uVar4 - param_2) >> 3) - ((int)(uVar4 - param_2) >> 0x1f) >> 1;
      uVar2 = *(uint *)(param_2 + iVar3 * 8);
      uVar1 = param_2 + iVar3 * 8;
      if (uVar2 < *param_1) {
        param_2 = uVar1 + 8;
      }
      else {
        if (uVar2 <= *param_1) {
          *param_4 = 1;
          return uVar1;
        }
        uVar4 = uVar1 - 8;
      }
    } while (param_2 <= uVar4);
  }
  *param_4 = 0;
  return param_2;
}

