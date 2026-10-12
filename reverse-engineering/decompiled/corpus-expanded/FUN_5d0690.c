/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0690; label: FUN_005d0690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d0690(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x34);
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x30)) {
      do {
        iVar1 = FUN_004f8b10(param_2,*(undefined4 *)(iVar3 + 4));
        if (iVar1 == 0) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0xc;
      } while (iVar2 < *(int *)(param_1 + 0x30));
    }
  }
  return 0;
}

