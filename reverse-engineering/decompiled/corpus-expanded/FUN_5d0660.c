/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0660; label: FUN_005d0660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0660(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  undefined8 uVar3;
  
  if (param_1 != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x30)) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x34) + 4);
      do {
        uVar3 = FUN_005c1300(iVar1,*puVar2);
        iVar1 = (int)uVar3 + 1;
        puVar2 = (undefined4 *)(extraout_ECX + 0xc);
      } while (iVar1 < *(int *)((int)((ulonglong)uVar3 >> 0x20) + 0x30));
    }
  }
  return;
}

