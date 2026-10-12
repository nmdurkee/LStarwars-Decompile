/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x566f70; label: FUN_00566f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00566f70(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((((param_2 != 0) && (0 < *(int *)(param_2 + 0x50bc))) && (param_1 != (undefined4 *)0x0)) &&
     ((*(undefined4 **)(param_2 + 0x50c4) <= param_1 &&
      (puVar5 = *(undefined4 **)(param_2 + 0x50c4) +
                (uint)*(ushort *)(*(int *)(param_2 + 0x128) + 0xdc) * 0x40, param_1 <= puVar5)))) {
    puVar4 = param_1;
    if (param_1 < puVar5 + -0x40) {
      while (puVar4 = puVar4 + 0x40, puVar4 <= puVar5 + -0x40) {
        iVar3 = 0;
        if (0 < *(int *)(param_2 + 0x50c0)) {
          iVar2 = 0;
          do {
            puVar1 = *(undefined4 **)(*(int *)(param_2 + 0x50c8) + 0xa4 + iVar2);
            if (puVar1 == puVar4) {
              *(undefined4 **)(*(int *)(param_2 + 0x50c8) + iVar2 + 0xa4) = puVar1 + -0x40;
            }
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 0x114;
          } while (iVar3 < *(int *)(param_2 + 0x50c0));
        }
      }
    }
    puVar5 = param_1;
    if (param_1 !=
        (undefined4 *)((*(int *)(param_2 + 0x50bc) + -1) * 0x100 + *(int *)(param_2 + 0x50c4))) {
      do {
        param_1 = puVar5 + 0x40;
        puVar4 = param_1;
        for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        puVar5 = param_1;
      } while (param_1 !=
               (undefined4 *)
               ((*(int *)(param_2 + 0x50bc) + -1) * 0x100 + *(int *)(param_2 + 0x50c4)));
    }
    _memset(param_1,0,0x100);
    *(int *)(param_2 + 0x50bc) = *(int *)(param_2 + 0x50bc) + -1;
  }
  return;
}

