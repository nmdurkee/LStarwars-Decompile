/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5270; label: FUN_005e5270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005e5270(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (param_2 != 0) {
      *(int *)(DAT_0097157c + -4 + param_2 * 4) = param_1;
      return param_2;
    }
    iVar1 = 0;
    if (0 < DAT_0096e570) {
      do {
        if (*(int *)(DAT_0097157c + iVar1 * 4) == 0) {
          *(int *)(DAT_0097157c + iVar1 * 4) = param_1;
          return iVar1 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_0096e570);
    }
    FUN_005c12e0();
  }
  return 0;
}

