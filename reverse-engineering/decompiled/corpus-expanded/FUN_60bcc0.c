/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60bcc0; label: FUN_0060bcc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060bcc0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = (uint)param_1;
  if (*(uint *)(in_ECX + 0x14) < param_1) {
    FUN_006e67fd();
  }
  uVar2 = *(int *)(in_ECX + 0x14) - (int)param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  if (param_2 != 0) {
    puVar5 = (undefined4 *)(in_ECX + 4);
    puVar4 = puVar5;
    param_1 = puVar5;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar4 = (undefined4 *)*puVar5;
      param_1 = (undefined4 *)*puVar5;
    }
    _memmove_s((void *)((int)puVar4 + uVar1),*(uint *)(in_ECX + 0x18) - uVar1,
               (void *)((int)param_1 + param_2 + uVar1),uVar2 - param_2);
    iVar3 = *(int *)(in_ECX + 0x14) - param_2;
    *(int *)(in_ECX + 0x14) = iVar3;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    *(undefined1 *)(iVar3 + (int)puVar5) = 0;
  }
  return;
}

