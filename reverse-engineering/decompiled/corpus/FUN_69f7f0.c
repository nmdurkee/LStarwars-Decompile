/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69f7f0; label: FUN_0069f7f0
 */

undefined4 FUN_0069f7f0(int *param_1,int *param_2)

{
  int *piVar1;
  size_t _NewSize;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  void *pvVar10;
  uint uVar11;
  uint *puVar12;
  byte bVar13;
  undefined8 uVar14;
  int local_28;
  size_t local_24;
  void *local_20;
  
  local_20 = (void *)param_2[2];
  local_24 = param_2[3];
  iVar4 = *param_2;
  cVar2 = *(char *)(iVar4 + 4);
  bVar3 = *(byte *)(iVar4 + 5);
  bVar13 = bVar3 & 2;
  local_28 = 0;
  uVar14 = FUN_0069ece0(param_2);
  iVar6 = *(int *)(iVar4 + 0xe);
  iVar8 = param_1[9];
  iVar7 = *(int *)(iVar4 + 0x12);
  iVar5 = param_1[3];
  uVar11 = (uint)*(byte *)(iVar4 + 0x1a);
  if (iVar5 != 0) {
    piVar1 = param_1 + 2;
    *piVar1 = *piVar1 - iVar5;
    if (*piVar1 != 0) {
      _memmove((void *)*param_1,(void *)(*param_1 + iVar5),param_1[2]);
    }
    param_1[3] = 0;
  }
  if (iVar8 != 0) {
    if (param_1[7] - iVar8 != 0) {
      _memmove((void *)param_1[4],(void *)(param_1[4] + iVar8 * 4),(param_1[7] - iVar8) * 4);
      _memmove((void *)param_1[5],(void *)(param_1[5] + iVar8 * 8),(param_1[7] - iVar8) * 8);
    }
    param_1[7] = param_1[7] - iVar8;
    param_1[8] = param_1[8] - iVar8;
    param_1[9] = 0;
  }
  if ((iVar6 != param_1[0x54]) || (cVar2 != '\0')) {
    return 0xffffffff;
  }
  FUN_0069ef10();
  if (iVar7 != param_1[0x55]) {
    iVar8 = param_1[8];
    if (iVar8 < param_1[7]) {
      puVar12 = (uint *)(param_1[4] + iVar8 * 4);
      do {
        param_1[2] = param_1[2] - (*puVar12 & 0xff);
        iVar8 = iVar8 + 1;
        puVar12 = puVar12 + 1;
      } while (iVar8 < param_1[7]);
      iVar8 = param_1[8];
    }
    param_1[7] = iVar8;
    if (param_1[0x55] != -1) {
      *(undefined4 *)(param_1[4] + iVar8 * 4) = 0x400;
      param_1[7] = param_1[7] + 1;
      param_1[8] = param_1[8] + 1;
    }
  }
  if (((bVar3 & 1) != 0) &&
     ((param_1[7] < 1 || (*(int *)(param_1[4] + -4 + param_1[7] * 4) == 0x400)))) {
    bVar13 = 0;
    if (uVar11 != 0) {
      do {
        uVar9 = (uint)*(byte *)(iVar4 + 0x1b + local_28);
        local_20 = (void *)((int)local_20 + uVar9);
        local_24 = local_24 - uVar9;
        local_28 = local_28 + 1;
        if (uVar9 < 0xff) break;
      } while (local_28 < (int)uVar11);
      goto LAB_0069f9d7;
    }
  }
  local_28 = 0;
LAB_0069f9d7:
  if (local_24 != 0) {
    if (param_1[1] <= (int)(param_1[2] + local_24)) {
      _NewSize = param_1[1] + 0x400 + local_24;
      param_1[1] = _NewSize;
      pvVar10 = _realloc((void *)*param_1,_NewSize);
      *param_1 = (int)pvVar10;
    }
    _memcpy((void *)(param_1[2] + *param_1),local_20,local_24);
    param_1[2] = param_1[2] + local_24;
  }
  iVar8 = -1;
  if (local_28 < (int)uVar11) {
    do {
      uVar9 = (uint)*(byte *)(iVar4 + 0x1b + local_28);
      *(uint *)(param_1[4] + param_1[7] * 4) = uVar9;
      iVar5 = param_1[5];
      iVar6 = param_1[7];
      *(undefined4 *)(iVar5 + iVar6 * 8) = 0xffffffff;
      *(undefined4 *)(iVar5 + 4 + iVar6 * 8) = 0xffffffff;
      if (bVar13 != 0) {
        puVar12 = (uint *)(param_1[4] + param_1[7] * 4);
        *puVar12 = *puVar12 | 0x100;
        bVar13 = 0;
      }
      if (uVar9 < 0xff) {
        iVar8 = param_1[7];
      }
      param_1[7] = param_1[7] + 1;
      local_28 = local_28 + 1;
      if (uVar9 < 0xff) {
        param_1[8] = param_1[7];
      }
    } while (local_28 < (int)uVar11);
    if (iVar8 != -1) {
      iVar4 = param_1[5];
      *(int *)(iVar4 + iVar8 * 8) = (int)uVar14;
      *(int *)(iVar4 + 4 + iVar8 * 8) = (int)((ulonglong)uVar14 >> 0x20);
    }
  }
  if ((bVar3 & 4) != 0) {
    param_1[0x52] = 1;
    if (0 < param_1[7]) {
      puVar12 = (uint *)(param_1[4] + -4 + param_1[7] * 4);
      *puVar12 = *puVar12 | 0x200;
    }
  }
  param_1[0x55] = iVar7 + 1;
  return 0;
}

