/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dde00; label: FUN_005dde00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dde00(int param_1,uint *param_2,undefined4 param_3,void *param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9,int param_10)

{
  size_t _Size;
  undefined1 *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  void *_Dst;
  
  puVar2 = param_2;
  *param_2 = *param_2 + 0xf & 0xfffffff0;
  *(void **)(param_1 + 4) = param_4;
  *(uint *)(param_1 + 8) = *param_2 + 0xf & 0xfffffff0;
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + (int)param_4 * 0x10;
  *(int *)(param_1 + 0x4c) = param_5;
  uVar3 = *param_2 + 0xf & 0xfffffff0;
  *param_2 = uVar3;
  *(uint *)(param_1 + 0x50) = uVar3;
  _Size = param_5 * 4;
  uVar3 = (*param_2 + 0xf & 0xfffffff0) + _Size;
  *param_2 = uVar3;
  *(uint *)(param_1 + 0x54) = uVar3 + 0xf & 0xfffffff0;
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + _Size;
  _memset(*(void **)(param_1 + 0x50),0,_Size);
  _memset(*(void **)(param_1 + 0x54),0,_Size);
  if (param_10 != 0) {
    uVar3 = *param_2;
    *param_2 = (uVar3 + 0xf & 0xfffffff0) + param_5 * 0x2c4;
    uVar3 = uVar3 + 0xf & 0xfffffff0;
    iVar4 = 0;
    if (0 < param_5) {
      do {
        *(uint *)(*(int *)(param_1 + 0x50) + iVar4 * 4) = uVar3;
        iVar4 = iVar4 + 1;
        uVar3 = uVar3 + 0x2c4;
      } while (iVar4 < param_5);
    }
  }
  _Dst = (void *)(*param_2 + 0xf & 0xfffffff0);
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + param_5 * 0x44;
  _memset(_Dst,0,param_5 * 0x44);
  param_4 = (void *)(*param_2 + 0xf & 0xfffffff0);
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + param_5 * 0x10;
  _memset(param_4,0,param_5 * 0x10);
  param_2 = (uint *)0x0;
  if (0 < param_5) {
    do {
      *(void **)(*(int *)(param_1 + 0x54) + (int)param_2 * 4) = _Dst;
      *(uint *)((int)_Dst + 8) = *puVar2 + 3 & 0xfffffffc;
      *puVar2 = (*puVar2 + 3 & 0xfffffffc) + 0x34;
      *(void **)((int)_Dst + 0x10) = param_4;
      FUN_005fca40(*(undefined4 *)((int)_Dst + 8));
      param_4 = (void *)((int)param_4 + 0x10);
      param_2 = (uint *)((int)param_2 + 1);
      _Dst = (void *)((int)_Dst + 0x44);
    } while ((int)param_2 < param_5);
  }
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  if (*(int *)(param_1 + 0x4c) != 0) {
    do {
      puVar1 = *(undefined1 **)(*(int *)(*(int *)(param_1 + 0x54) + uVar3 * 4) + 0x10);
      uVar3 = uVar3 + 1;
      *puVar1 = 0x8d;
      *(undefined4 *)(puVar1 + 4) = 0;
      puVar1[1] = 1;
    } while (uVar3 < *(uint *)(param_1 + 0x4c));
  }
  iVar4 = param_5 + 7 + (param_5 + 7 >> 0x1f & 7U);
  *(uint *)(param_1 + 0x58) = *puVar2 + 0xf & 0xfffffff0;
  iVar4 = (((int)((iVar4 >> 3) + (iVar4 >> 0x1f & 0xfU)) >> 4) + 1) * 0x10;
  uVar3 = (*puVar2 + 0xf & 0xfffffff0) + iVar4;
  *puVar2 = uVar3;
  *(uint *)(param_1 + 0x5c) = uVar3;
  *puVar2 = (*puVar2 + 0xf & 0xfffffff0) + iVar4;
  *(int *)(param_1 + 0x60) = param_8;
  *(uint *)(param_1 + 100) = *puVar2;
  *puVar2 = *puVar2 + param_8 * 0x24;
  _memset(*(void **)(param_1 + 100),0,param_8 * 0x24);
  if (0 < param_8) {
    iVar4 = 0;
    do {
      *(int *)(iVar4 + 0x1c + *(int *)(param_1 + 100)) = param_1;
      *(undefined2 *)(iVar4 + 0x20 + *(int *)(param_1 + 100)) = 0;
      *(undefined2 *)(iVar4 + 0x22 + *(int *)(param_1 + 100)) = 0;
      iVar4 = iVar4 + 0x24;
      param_8 = param_8 + -1;
    } while (param_8 != 0);
  }
  FUN_006034a0(param_1,puVar2,param_3);
  FUN_005ddd10(1);
  return;
}

