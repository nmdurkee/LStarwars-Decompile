/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590140; label: FUN_00590140
 */

void FUN_00590140(int param_1,int param_2)

{
  undefined4 *_Dst;
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) & 0xfdff | 3;
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x40) = DAT_029959a0;
  if ((*(int *)(param_1 + 0x10) != 0) &&
     (piVar3 = *(int **)(*(int *)(param_1 + 0x10) + 0x18), piVar3 != (int *)0x0)) {
    local_4c = 1e+09;
    local_64 = 1e+09;
    local_58 = -1e+09;
    local_70 = -1e+09;
    local_54 = -1e+09;
    local_6c = -1e+09;
    local_50 = -1e+09;
    local_68 = -1e+09;
    local_48 = 1e+09;
    local_60 = 1e+09;
    local_44 = 1e+09;
    local_5c = 1e+09;
    do {
      _Dst = (undefined4 *)piVar3[9];
      _memset(_Dst,0,200);
      FUN_005526c0(piVar3 + 1,piVar3[6],local_40,1);
      puVar4 = local_40;
      puVar5 = _Dst;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      if (*(int *)(param_1 + 0x18) != 0) {
        _Dst[0xc] = (float)_Dst[0xc] - *(float *)(*(int *)(param_1 + 0x18) + 0x1c);
        _Dst[0xd] = (float)_Dst[0xd] - *(float *)(*(int *)(param_1 + 0x18) + 0x20);
        _Dst[0xe] = (float)_Dst[0xe] - *(float *)(*(int *)(param_1 + 0x18) + 0x24);
        FUN_005b4f70(_Dst,*(undefined2 *)(param_1 + 0x74));
        _Dst[0xc] = *(float *)(param_1 + 0x1c) + (float)_Dst[0xc];
        _Dst[0xd] = *(float *)(param_1 + 0x20) + (float)_Dst[0xd];
        _Dst[0xe] = *(float *)(param_1 + 0x24) + (float)_Dst[0xe];
        puVar4 = _Dst;
        puVar5 = _Dst + 0x20;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      FUN_005526c0(piVar3 + 1,piVar3[7],local_40,1);
      puVar4 = local_40;
      puVar5 = _Dst + 0x10;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      if (*(int *)(param_1 + 0x18) != 0) {
        _Dst[0x1c] = (float)_Dst[0x1c] - *(float *)(*(int *)(param_1 + 0x18) + 0x1c);
        _Dst[0x1d] = (float)_Dst[0x1d] - *(float *)(*(int *)(param_1 + 0x18) + 0x20);
        _Dst[0x1e] = (float)_Dst[0x1e] - *(float *)(*(int *)(param_1 + 0x18) + 0x24);
        FUN_005b4f70(_Dst + 0x10,*(undefined2 *)(param_1 + 0x74));
        _Dst[0x1c] = *(float *)(param_1 + 0x1c) + (float)_Dst[0x1c];
        _Dst[0x1d] = *(float *)(param_1 + 0x20) + (float)_Dst[0x1d];
        _Dst[0x1e] = *(float *)(param_1 + 0x24) + (float)_Dst[0x1e];
      }
      if ((float)_Dst[0xc] < local_64) {
        local_64 = (float)_Dst[0xc];
      }
      if (local_70 < (float)_Dst[0xc]) {
        local_70 = (float)_Dst[0xc];
      }
      if ((float)_Dst[0xd] < local_60) {
        local_60 = (float)_Dst[0xd];
      }
      if (local_6c < (float)_Dst[0xd]) {
        local_6c = (float)_Dst[0xd];
      }
      if ((float)_Dst[0xe] < local_5c) {
        local_5c = (float)_Dst[0xe];
      }
      if (local_68 < (float)_Dst[0xe]) {
        local_68 = (float)_Dst[0xe];
      }
      if ((float)_Dst[0x1c] < local_4c) {
        local_4c = (float)_Dst[0x1c];
      }
      if (local_58 < (float)_Dst[0x1c]) {
        local_58 = (float)_Dst[0x1c];
      }
      if ((float)_Dst[0x1d] < local_48) {
        local_48 = (float)_Dst[0x1d];
      }
      if (local_54 < (float)_Dst[0x1d]) {
        local_54 = (float)_Dst[0x1d];
      }
      if ((float)_Dst[0x1e] < local_44) {
        local_44 = (float)_Dst[0x1e];
      }
      if (local_50 < (float)_Dst[0x1e]) {
        local_50 = (float)_Dst[0x1e];
      }
      _Dst[0x30] = 0x3e4ccccd;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    *(float *)(param_1 + 0x28) = (local_64 + local_70) * 0.5;
    *(float *)(param_1 + 0x2c) = (local_6c + local_60) * 0.5;
    *(float *)(param_1 + 0x30) = (local_5c + local_68) * 0.5;
    local_68 = local_68 - local_5c;
    if (local_68 < local_70 - local_64) {
      local_68 = local_70 - local_64;
    }
    *(float *)(param_1 + 0x40) = local_68;
    *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) * DAT_029959a0;
    *(float *)(param_1 + 0x34) = (local_58 + local_4c) * 0.5;
    *(float *)(param_1 + 0x38) = (local_54 + local_48) * 0.5;
    *(float *)(param_1 + 0x3c) = (local_50 + local_44) * 0.5;
  }
  if (*(short *)(param_1 + 0x54) == 0) {
    *(ushort *)(param_1 + 0x72) = *(ushort *)(param_1 + 0x72) & 0xfffe;
  }
  else {
    *(ushort *)(param_1 + 0x72) = *(ushort *)(param_1 + 0x72) | 1;
  }
  *(undefined1 *)(param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x6f) = 0;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x13c) != 0) {
      uVar1 = FUN_005d92b0(*(int *)(param_2 + 0x13c),param_1 + 0x1c);
      *(undefined2 *)(param_1 + 0x76) = uVar1;
      return;
    }
    *(undefined2 *)(param_1 + 0x76) = 0xffff;
  }
  return;
}

