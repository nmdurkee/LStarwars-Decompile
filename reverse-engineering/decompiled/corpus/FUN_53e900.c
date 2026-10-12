/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53e900; label: FUN_0053e900
 */

void FUN_0053e900(void)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int *in_EAX;
  int *piVar4;
  int in_EDX;
  int iVar5;
  int iVar6;
  int local_8;
  undefined2 local_4;
  
  if (in_EAX != (int *)0x0) {
    fVar3 = *(float *)(in_EDX + 4);
    piVar4 = (int *)(*(char *)(in_EDX + 1) * 0x13c + *in_EAX);
    iVar5 = (int)*(short *)(in_EDX + 2);
    iVar6 = (int)*(short *)(in_EDX + 0x28);
    pfVar1 = (float *)(*(int *)(*piVar4 + 8) + iVar5 * 0xc);
    pfVar2 = (float *)(*(int *)(*piVar4 + 8) + iVar6 * 0xc);
    DAT_009242e0 = *pfVar1 + fVar3 * (*pfVar2 - *pfVar1);
    DAT_009242e4 = (pfVar2[1] - pfVar1[1]) * fVar3 + pfVar1[1];
    DAT_009242e8 = (pfVar2[2] - pfVar1[2]) * fVar3 + pfVar1[2];
    local_8 = (uint)*(ushort *)(piVar4[0xe] + iVar6 * 4) -
              (uint)*(ushort *)(piVar4[0xe] + iVar5 * 4);
    if (local_8 < 0x8001) {
      if (local_8 < -0x8000) {
        local_8 = local_8 + 0x10000;
      }
    }
    else {
      local_8 = local_8 + -0x10000;
    }
    local_4 = (undefined2)
              (int)ROUND((float)*(ushort *)(piVar4[0xe] + iVar5 * 4) +
                         (float)local_8 * *(float *)(in_EDX + 4));
    *(undefined2 *)(in_EDX + 0x20) = local_4;
    local_8 = (uint)*(ushort *)(piVar4[0xe] + 2 + iVar6 * 4) -
              (uint)*(ushort *)(piVar4[0xe] + 2 + iVar5 * 4);
    if (local_8 < 0x8001) {
      if (local_8 < -0x8000) {
        local_8 = local_8 + 0x10000;
      }
    }
    else {
      local_8 = local_8 + -0x10000;
    }
    local_4 = (undefined2)
              (int)ROUND((float)*(ushort *)(piVar4[0xe] + 2 + iVar5 * 4) +
                         (float)local_8 * *(float *)(in_EDX + 4));
    *(undefined2 *)(in_EDX + 0x22) = local_4;
    local_8 = (uint)*(ushort *)(piVar4[0xf] + iVar6 * 4) -
              (uint)*(ushort *)(piVar4[0xf] + iVar5 * 4);
    if (local_8 < 0x8001) {
      if (local_8 < -0x8000) {
        local_8 = local_8 + 0x10000;
      }
    }
    else {
      local_8 = local_8 + -0x10000;
    }
    local_4 = (undefined2)
              (int)ROUND((float)*(ushort *)(piVar4[0xf] + iVar5 * 4) +
                         (float)local_8 * *(float *)(in_EDX + 4));
    *(undefined2 *)(in_EDX + 0x24) = local_4;
    local_8 = (uint)*(ushort *)(piVar4[0xf] + 2 + iVar6 * 4) -
              (uint)*(ushort *)(piVar4[0xf] + 2 + iVar5 * 4);
    if (local_8 < 0x8001) {
      if (local_8 < -0x8000) {
        local_8 = local_8 + 0x10000;
      }
    }
    else {
      local_8 = local_8 + -0x10000;
    }
    local_4 = (undefined2)
              (int)ROUND((float)*(ushort *)(piVar4[0xf] + 2 + iVar5 * 4) +
                         (float)local_8 * *(float *)(in_EDX + 4));
    *(undefined2 *)(in_EDX + 0x26) = local_4;
    fVar3 = (float)(int)*(short *)(in_EDX + 2) + *(float *)(in_EDX + 4);
    *(float *)(in_EDX + 0x2c) = fVar3;
    if (*(char *)((int)piVar4 + 0x33) != '\0') {
      *(float *)(in_EDX + 0x30) = fVar3 / (float)(*(ushort *)(piVar4 + 0xc) + 1);
      return;
    }
    *(float *)(in_EDX + 0x30) = fVar3 / (float)*(ushort *)(piVar4 + 0xc);
  }
  return;
}

