/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cb310; label: FUN_004cb310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cb310(int param_1,int *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  iVar4 = *param_2;
  if (0.0 < *(float *)(iVar4 + 0x1090)) {
    *(int *)(param_1 + 0x104) = param_2[0x17];
    *(int *)(param_1 + 0x108) = param_2[0x18];
    iVar4 = param_2[0x19];
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(int *)(param_1 + 0x10c) = iVar4;
    *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
    return 1;
  }
  cVar3 = *(char *)(iVar4 + 0x7b5);
  iVar5 = (uint)*(byte *)((*(char *)(param_1 + 0x160) == '\0') + 0x10 + *(int *)(param_1 + 0x15c)) *
          0x5c + *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  if (((cVar3 != '\x0f') && (cVar3 != 'G')) &&
     ((cVar3 != '\0' || (*(char *)(iVar4 + 0x7b8) != '\x06')))) {
    iVar5 = FUN_0043c9a0(iVar4,iVar5,0);
    if (iVar5 == 0) {
      puVar2 = (undefined4 *)
               ((uint)*(byte *)(*(byte *)(param_1 + 0x160) + 0x10 + *(int *)(param_1 + 0x15c)) *
                0x5c + 4 + *(int *)(*(int *)(param_1 + 0x158) + 0x7c));
      *(undefined4 *)(param_1 + 0x104) = *puVar2;
      *(undefined4 *)(param_1 + 0x108) = puVar2[1];
      *(undefined4 *)(param_1 + 0x10c) = puVar2[2];
      *(undefined4 *)(param_1 + 0x110) = 0;
      puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 4);
      *puVar1 = *puVar1 | DAT_00802280;
      puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802280;
      uVar6 = *(uint *)(*(int *)(param_1 + 0x15c) + (uint)*(byte *)(param_1 + 0x160) * 4) &
              *(uint *)(param_1 + 500);
      if ((uVar6 & 0x10) == 0) {
        if ((uVar6 & 8) == 0) {
          *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
          return 1;
        }
        uVar7 = 4;
      }
      else {
        uVar7 = 3;
      }
      FUN_0055dd70(iVar4,0,uVar7,1,0);
      *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
    }
    return 1;
  }
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar5 + 4);
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(iVar5 + 8);
  uVar7 = *(undefined4 *)(iVar5 + 0xc);
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x10c) = uVar7;
  FUN_0043cbb0(iVar4,iVar5,0,2);
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

