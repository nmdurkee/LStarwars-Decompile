/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1590; label: FUN_005a1590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a1590(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar3 = 0;
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar2 = FUN_005cfd60(puVar1 + 1);
      if (iVar2 != 0) {
        uVar3 = uVar3 + 1;
      }
    }
    if (uVar3 == *(byte *)(param_1 + 8)) {
      return 2;
    }
    if (0 < (int)uVar3) {
      return 1;
    }
  }
  return 0;
}

