/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x406b70; label: FUN_00406b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00406b70(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *param_3;
  iVar3 = *(int *)(iVar2 + 0x44c);
  *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar3 + 8);
  uVar4 = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar2 + 0x3d8) = 0;
  *(undefined4 *)(iVar2 + 0x3d4) = uVar4;
  *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
  *(uint *)(iVar2 + 0xef4) = *(uint *)(iVar2 + 0xef4) | 0x4000;
  if (*(char *)(iVar2 + 0x1087) == '\0') {
    if (*(char *)(iVar2 + 0x7b5) != '\0') {
      puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
      return 1;
    }
    *(undefined1 *)(iVar2 + 0x1087) = 1;
  }
  if ((*(char *)(iVar2 + 0x7b5) != 'D') &&
     ((*(char *)(iVar2 + 0x7b5) == '\0' ||
      ((*(char *)(iVar2 + 0x281) == '\0' &&
       (*(float *)(*(int *)(iVar2 + 0x44c) + 0x18) <= *(float *)(iVar2 + 0x60))))))) {
    return 1;
  }
  FUN_0043cbf0(iVar2);
  return 0;
}

