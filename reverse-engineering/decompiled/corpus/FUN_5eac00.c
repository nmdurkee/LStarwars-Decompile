/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5eac00; label: FUN_005eac00
 */

void * FUN_005eac00(int param_1,byte param_2,uint param_3,int *param_4)

{
  uint *puVar1;
  short *psVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  void *_Dst;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined2 local_4;
  
  piVar3 = *(int **)(DAT_0097157c + -4 + *(short *)(*(int *)(param_1 + 0x18) + 0x74) * 4);
  fVar4 = (float)*piVar3;
  fVar5 = (float)piVar3[1];
  _Dst = (void *)(*param_4 + 0xfU & 0xfffffff0);
  *param_4 = (*param_4 + 0xfU & 0xfffffff0) + 0xa4;
  _memset(_Dst,0,0xa4);
  *(int *)((int)_Dst + 0x48) = (int)_Dst + 0x4c;
  *(undefined4 *)((int)_Dst + 0xc) = *(undefined4 *)(param_1 + 0x1c);
  *(int *)((int)_Dst + 0x28) = param_1;
  *(float *)((int)_Dst + 0x14) = (float)(int)*(short *)(param_1 + 0xc);
  pfVar6 = (float *)(param_1 + 0x120);
  *(float *)((int)_Dst + 0x18) = (float)(int)*(short *)(param_1 + 0x14);
  *(float *)((int)_Dst + 0x24) = (float)(int)*(short *)(param_1 + 0x16);
  *(float *)((int)_Dst + 0x1c) = fVar4 * *(float *)(param_1 + 0x128) - fVar4 * *pfVar6;
  *(int *)((int)_Dst + 0x3c) = *param_4;
  *(undefined4 *)*param_4 = *(undefined4 *)((int)_Dst + 0x24);
  *param_4 = *param_4 + 4;
  *(undefined4 *)*param_4 = *(undefined4 *)((int)_Dst + 0x14);
  *param_4 = *param_4 + 4;
  *(float *)*param_4 = 1.0 / fVar4;
  *param_4 = *param_4 + 4;
  *(float *)*param_4 = 1.0 / fVar5;
  *param_4 = *param_4 + 4;
  *(undefined4 *)*param_4 = 0;
  *param_4 = *param_4 + 4;
  *(undefined4 *)*param_4 = 0;
  *param_4 = *param_4 + 4;
  *(undefined4 *)*param_4 = *(undefined4 *)((int)_Dst + 0x1c);
  *param_4 = *param_4 + 4;
  *(undefined4 *)*param_4 = 0;
  *param_4 = *param_4 + 4;
  *(int *)((int)_Dst + 0x2c) = *param_4;
  *(undefined4 *)*param_4 = 0x3f800000;
  *param_4 = *param_4 + 4;
  *(int *)((int)_Dst + 0x30) = *param_4;
  *(undefined4 *)*param_4 = 0x3f000000;
  *param_4 = *param_4 + 4;
  *(int *)((int)_Dst + 0x34) = *param_4;
  iVar8 = 0;
  while( true ) {
    iVar9 = *(int *)(param_1 + 0x1c);
    if (0xff < iVar9) {
      iVar9 = 0x100;
    }
    if (iVar9 <= iVar8) break;
    iVar8 = iVar8 + 1;
    *(float *)*param_4 = *pfVar6 * fVar4;
    *param_4 = *param_4 + 4;
    *(float *)*param_4 = pfVar6[1] * fVar5;
    *param_4 = *param_4 + 4;
    *(float *)*param_4 = pfVar6[2] * fVar4 - *pfVar6 * fVar4;
    *param_4 = *param_4 + 4;
    pfVar6 = pfVar6 + 5;
  }
  *(int *)((int)_Dst + 0x38) = *param_4;
  iVar8 = 0;
  do {
    cVar7 = *(char *)(param_1 + 0x20 + iVar8);
    if (cVar7 == -1) {
      cVar7 = '\0';
    }
    if (iVar8 == 0x20) {
      cVar7 = (char)*(undefined4 *)(param_1 + 0x1c);
    }
    *(char *)*param_4 = cVar7;
    *param_4 = *param_4 + 1;
    cVar7 = *(char *)(param_1 + 0x21 + iVar8);
    if (cVar7 == -1) {
      cVar7 = '\0';
    }
    if (iVar8 == 0x1f) {
      cVar7 = (char)*(undefined4 *)(param_1 + 0x1c);
    }
    *(char *)*param_4 = cVar7;
    *param_4 = *param_4 + 1;
    cVar7 = *(char *)(param_1 + 0x22 + iVar8);
    if (cVar7 == -1) {
      cVar7 = '\0';
    }
    if (iVar8 == 0x1e) {
      cVar7 = (char)*(undefined4 *)(param_1 + 0x1c);
    }
    *(char *)*param_4 = cVar7;
    *param_4 = *param_4 + 1;
    cVar7 = *(char *)(param_1 + 0x23 + iVar8);
    if (cVar7 == -1) {
      cVar7 = '\0';
    }
    if (iVar8 == 0x1d) {
      cVar7 = (char)*(undefined4 *)(param_1 + 0x1c);
    }
    *(char *)*param_4 = cVar7;
    *param_4 = *param_4 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x100);
  *(uint *)((int)_Dst + 0x40) = *param_4 + 0xfU & 0xfffffff0;
  *param_4 = (*param_4 + 0xfU & 0xfffffff0) + 0x2c4;
  puVar10 = *(undefined4 **)(param_1 + 0x18);
  puVar11 = *(undefined4 **)((int)_Dst + 0x40);
  for (iVar8 = 0xb1; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  FUN_006017c0(*(undefined4 *)((int)_Dst + 0x40),param_3 & 0xffff);
  if ((param_2 & 8) == 0) {
    puVar1 = (uint *)(*(int *)((int)_Dst + 0x40) + 0x44);
    *puVar1 = *puVar1 | 4;
  }
  else {
    puVar1 = (uint *)(*(int *)((int)_Dst + 0x40) + 0x44);
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  *(uint *)(*(int *)((int)_Dst + 0x40) + 0x40) =
       *(uint *)(*(int *)((int)_Dst + 0x40) + 0x40) & 0xfffeffff | 0x20000;
  iVar8 = *(int *)((int)_Dst + 0x40);
  if ((param_2 & 2) == 0) {
    *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xfffffff1 | 1;
  }
  else {
    *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xfffffff0;
  }
  iVar8 = *(int *)((int)_Dst + 0x40);
  if ((param_2 & 0x40) == 0) {
    if ((param_2 & 0x20) == 0) {
      *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) | 0xc000;
    }
    else {
      *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xffff7fff | 0x4000;
    }
  }
  else {
    *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xffff3fff;
  }
  iVar8 = *(int *)((int)_Dst + 0x40);
  if ((param_2 & 4) == 0) {
    if ((param_2 & 0x10) == 0) {
      *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xffffffcf;
    }
    else {
      *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xffffffef | 0x20;
    }
  }
  else {
    *(uint *)(iVar8 + 0x40) = *(uint *)(iVar8 + 0x40) & 0xffffffdf | 0x10;
  }
  local_4 = (undefined2)(param_3 >> 0x10);
  *(undefined2 *)(*(int *)((int)_Dst + 0x40) + 0x76) = local_4;
  iVar8 = *(int *)((int)_Dst + 0x40);
  FUN_00601030(iVar8);
  psVar2 = (short *)(iVar8 + 0x2c0);
  *psVar2 = *psVar2 + 1;
  *(undefined4 *)(*(int *)((int)_Dst + 0x48) + 0xc) = 0;
  *(undefined4 *)(*(int *)((int)_Dst + 0x48) + 8) = 0;
  *(undefined4 *)(*(int *)((int)_Dst + 0x48) + 4) = 0;
  return _Dst;
}

