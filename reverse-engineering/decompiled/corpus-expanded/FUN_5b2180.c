/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b2180; label: FUN_005b2180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b2180(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined8 uVar3;
  
  if ((DAT_0095e41c != 0) && (iVar1 = 0, 0 < DAT_0095e420)) {
    puVar2 = (undefined4 *)(DAT_0095e41c + 4);
    do {
      uVar3 = FUN_005b1eb0(iVar1,*puVar2);
      iVar1 = (int)uVar3 + 1;
      puVar2 = (undefined4 *)(extraout_ECX + 0xc);
    } while (iVar1 < (int)((ulonglong)uVar3 >> 0x20));
  }
  if (param_1 != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x30)) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x34) + 4);
      do {
        uVar3 = FUN_005b1eb0(iVar1,*puVar2);
        iVar1 = (int)uVar3 + 1;
        puVar2 = (undefined4 *)(extraout_ECX_00 + 0xc);
      } while (iVar1 < *(int *)((int)((ulonglong)uVar3 >> 0x20) + 0x30));
    }
  }
  return;
}

