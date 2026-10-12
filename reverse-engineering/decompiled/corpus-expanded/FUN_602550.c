/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x602550; label: FUN_00602550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602550(int param_1)

{
  ushort *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  
  puVar1 = *(ushort **)(param_1 + 0x1d0);
  iVar4 = 0;
  bVar3 = false;
  if (*(int *)(puVar1 + 10) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(puVar1 + 8) + iVar4 * 4);
      *(undefined4 *)(iVar2 + 0x20) =
           *(undefined4 *)((int)DAT_00986e94 + *(int *)(iVar2 + 0x20) * 4);
      *(undefined4 *)(iVar2 + 0x24) =
           *(undefined4 *)((int)DAT_00986e8c + *(int *)(iVar2 + 0x24) * 4);
      if (*(int *)(iVar2 + 0x28) != 0) {
        bVar3 = true;
        FUN_006df300();
        FUN_006e4810((uint)*(ushort *)(iVar2 + 8) * *(int *)(iVar2 + 0x18),0x208,0,0,iVar2 + 0x30);
        FUN_006df310();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != *(int *)(puVar1 + 10));
    if (bVar3) {
      iVar4 = 0;
      do {
        if ((&DAT_02854da0)[iVar4] == 0) {
          (&DAT_02854da0)[iVar4] = param_1;
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 100);
    }
  }
  iVar4 = 0;
  if (*(int *)(puVar1 + 0xe) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(puVar1 + 0xc) + iVar4 * 4);
      iVar4 = iVar4 + 1;
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)((int)DAT_00986e8c + *(int *)(iVar2 + 8) * 4);
    } while (iVar4 != *(int *)(puVar1 + 0xe));
  }
  *puVar1 = DAT_00986e88;
  puVar1[4] = DAT_00986e90;
  _memcpy(*(void **)(puVar1 + 2),DAT_00986e8c,(uint)DAT_00986e88 * 4);
  _memcpy(*(void **)(puVar1 + 6),DAT_00986e94,(uint)DAT_00986e90 * 4);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      FUN_005e4b00(*(undefined4 *)(*(int *)(param_1 + 0xc) + iVar4 * 4));
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x10));
  }
  FUN_005d9130(param_1,*(undefined4 *)(param_1 + 0x6c));
  return;
}

