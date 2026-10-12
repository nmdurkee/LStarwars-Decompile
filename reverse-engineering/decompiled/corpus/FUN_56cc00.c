/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56cc00; label: FUN_0056cc00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056cc00(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  
  iVar3 = param_1;
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x2ae8) != 0)) &&
      (*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) != 0)) && (*(int *)(param_1 + 0x467c) != 0)) {
    *(undefined2 *)(*(int *)(param_1 + 0x467c) + 4) = 0;
    _memset((void *)**(undefined4 **)(param_1 + 0x467c),0,
            (uint)*(ushort *)((int)*(undefined4 **)(param_1 + 0x467c) + 6) << 5);
    pbVar4 = *(byte **)(*(int *)(param_1 + 0x2ae8) + 0x10);
    param_1 = 0;
    if (*pbVar4 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(pbVar4 + 4) + param_1 * 4);
        if (iVar1 != 0) {
          puVar7 = *(uint **)(iVar1 + 0x80);
          iVar6 = 0;
          if (*(short *)(iVar1 + 0x12) != 0) {
            do {
              piVar2 = *(int **)(iVar3 + 0x467c);
              if ((*(ushort *)(piVar2 + 1) < *(ushort *)((int)piVar2 + 6)) &&
                 ((*puVar7 & (DAT_00950d4c | _DAT_00950d48)) != 0)) {
                iVar5 = (uint)*(ushort *)(piVar2 + 1) * 0x20 + *piVar2;
                *(ushort *)(piVar2 + 1) = *(ushort *)(piVar2 + 1) + 1;
                *(uint **)(iVar5 + 0x14) = puVar7;
                *(int *)(iVar5 + 0x18) = iVar1;
                FUN_0056cab0(iVar5);
              }
              iVar6 = iVar6 + 1;
              puVar7 = puVar7 + 9;
            } while (iVar6 < (int)(uint)*(ushort *)(iVar1 + 0x12));
          }
        }
        pbVar4 = *(byte **)(*(int *)(iVar3 + 0x2ae8) + 0x10);
        param_1 = param_1 + 1;
      } while (param_1 < (int)(uint)*pbVar4);
    }
  }
  return;
}

