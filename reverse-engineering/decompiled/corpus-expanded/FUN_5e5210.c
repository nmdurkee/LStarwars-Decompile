/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5210; label: FUN_005e5210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005e5210(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_009716e4;
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < DAT_0096e570) {
    do {
      if (*(int *)(DAT_0097157c + iVar2 * 4) == 0) {
        *(int *)(DAT_0097157c + iVar2 * 4) = param_1;
        *(int *)(iVar1 + iVar2 * 4) = DAT_00966380;
        DAT_00966380 = DAT_00966380 + 1;
        FUN_005f8e50(param_1);
        return iVar2 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0096e570);
  }
  FUN_005c12e0();
  return 0;
}

