/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0740; label: FUN_005d0740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d0740(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((0 < param_4) && (param_1 != 0)) {
    iVar3 = *(int *)(param_1 + 0x34);
    iVar2 = 0;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x30)) {
      do {
        iVar1 = FUN_004f8b80(param_2,*(undefined4 *)(iVar3 + 4),0xffffffff);
        if (iVar1 == 0) {
          *(int *)(param_3 + iVar4 * 4) = iVar3;
          iVar4 = iVar4 + 1;
          if (param_4 <= iVar4) {
            return iVar4;
          }
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0xc;
      } while (iVar2 < *(int *)(param_1 + 0x30));
    }
    return iVar4;
  }
  return 0;
}

