/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654e00; label: FUN_00654e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00654e00(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  iVar2 = *param_2;
  if (iVar2 == 0) {
    *param_2 = param_1;
    return;
  }
  iVar3 = *(int *)(iVar2 + 0x5c);
  uVar1 = *(ushort *)(param_1 + 0x60);
  if (*(ushort *)(iVar2 + 0x60) < uVar1) {
    *(int *)(param_1 + 0x5c) = iVar2;
    *(int *)(iVar2 + 0x58) = param_1;
    *param_2 = param_1;
    return;
  }
  if ((uVar1 == *(ushort *)(iVar2 + 0x60)) &&
     (*(char *)(*(int *)(param_1 + 4) + 0x2e) <= *(char *)(*(int *)(iVar2 + 4) + 0x2e))) {
    *(int *)(param_1 + 0x5c) = iVar2;
    *(int *)(iVar2 + 0x58) = param_1;
    *param_2 = param_1;
    return;
  }
  while ((iVar3 != 0 &&
         ((uVar1 < *(ushort *)(iVar3 + 0x60) ||
          ((uVar1 == *(ushort *)(iVar3 + 0x60) &&
           (*(char *)(*(int *)(iVar3 + 4) + 0x2e) < *(char *)(*(int *)(param_1 + 4) + 0x2e)))))))) {
    iVar2 = iVar3;
    iVar3 = *(int *)(iVar3 + 0x5c);
  }
  *(int *)(iVar2 + 0x5c) = param_1;
  *(int *)(param_1 + 0x58) = iVar2;
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x5c) = iVar3;
    *(int *)(iVar3 + 0x58) = param_1;
  }
  return;
}

