/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633b60; label: FUN_00633b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633b60(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  
  *(undefined4 *)(DAT_02913234 + 0x20) = *(undefined4 *)(param_2 + 0xc);
  *(int *)(DAT_02913234 + 0x1c) = *(int *)(param_2 + 0xc) + -3;
  if (*(uint *)(param_2 + 0xc) < 4) {
    bVar4 = *(int *)(param_2 + 0xc) == 3;
    iVar3 = 0;
    if (0 < *(int *)(DAT_02913234 + 0xc)) {
      do {
        *(uint *)(*(int *)(*(int *)(DAT_02913234 + 4) + iVar3 * 4) + 0xc) = (uint)bVar4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(DAT_02913234 + 0xc));
    }
    if (*(uint *)(param_2 + 0xc) < 2) {
      FUN_00624220(param_1);
      DAT_02913238 = 0;
    }
    else {
      iVar3 = 0;
      for (puVar2 = *(undefined4 **)*param_1; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        if (iVar3 < 3) {
          *(byte *)((int)puVar2 + 0x11) = *(byte *)((int)puVar2 + 0x11) & 0xfe;
        }
        else {
          *(byte *)((int)puVar2 + 0x11) =
               *(byte *)((int)puVar2 + 0x11) ^ (*(byte *)((int)puVar2 + 0x11) ^ bVar4) & 1;
        }
        iVar3 = iVar3 + 1;
      }
    }
    FUN_005d86d0(*(int *)(param_2 + 0xc) != 0);
    return;
  }
  puVar1 = (uint *)(*(int *)(*(int *)(DAT_02913234 + 4) + -0x10 + *(int *)(param_2 + 0xc) * 4) + 0xc
                   );
  *puVar1 = *puVar1 ^ 1;
  return;
}

