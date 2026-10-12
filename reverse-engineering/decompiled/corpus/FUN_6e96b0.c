/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e96b0; label: _qsort
 */

/* Library Function - Single Match
    _qsort
   
   Library: Visual Studio 2005 Release */

void __cdecl
_qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  size_t sVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *local_100;
  undefined1 *local_fc;
  int local_f4;
  undefined4 auStack_f0 [30];
  undefined4 auStack_78 [30];
  
  if ((_Base == (void *)0x0) && (_NumOfElements != 0)) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return;
  }
  if ((_SizeOfElements == 0) || (_PtFuncCompare == (_PtFuncCompare *)0x0)) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return;
  }
  if (_NumOfElements < 2) {
    return;
  }
  local_f4 = 0;
  local_100 = _Base;
  local_fc = (undefined1 *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
LAB_006e9753:
  while (uVar3 = (uint)((int)local_fc - (int)local_100) / _SizeOfElements + 1, 8 < uVar3) {
    puVar4 = local_100 + (uVar3 >> 1) * _SizeOfElements;
    iVar5 = (*_PtFuncCompare)(local_100,puVar4);
    if (0 < iVar5) {
      swap();
    }
    iVar5 = (*_PtFuncCompare)(local_100,local_fc);
    if (0 < iVar5) {
      swap();
    }
    iVar5 = (*_PtFuncCompare)(puVar4,local_fc);
    puVar8 = local_100;
    puVar9 = local_fc;
    if (0 < iVar5) {
      swap();
    }
LAB_006e9800:
    if (puVar8 < puVar4) {
      do {
        puVar8 = puVar8 + _SizeOfElements;
        if (puVar4 <= puVar8) goto LAB_006e9820;
        iVar5 = (*_PtFuncCompare)(puVar8,puVar4);
      } while (iVar5 < 1);
      if (puVar4 <= puVar8) goto LAB_006e9820;
    }
    else {
LAB_006e9820:
      do {
        puVar8 = puVar8 + _SizeOfElements;
        if (local_fc < puVar8) break;
        iVar5 = (*_PtFuncCompare)(puVar8,puVar4);
      } while (iVar5 < 1);
    }
    do {
      puVar9 = puVar9 + -_SizeOfElements;
      if (puVar9 <= puVar4) break;
      iVar5 = (*_PtFuncCompare)(puVar9,puVar4);
    } while (0 < iVar5);
    if (puVar8 <= puVar9) {
      if (puVar8 != puVar9) {
        puVar6 = puVar9;
        sVar7 = _SizeOfElements;
        do {
          uVar1 = puVar6[(int)puVar8 - (int)puVar9];
          puVar6[(int)puVar8 - (int)puVar9] = *puVar6;
          sVar7 = sVar7 - 1;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
        } while (sVar7 != 0);
      }
      if (puVar4 == puVar9) {
        puVar4 = puVar8;
      }
      goto LAB_006e9800;
    }
    puVar9 = puVar9 + _SizeOfElements;
    if (puVar4 < puVar9) {
      do {
        puVar9 = puVar9 + -_SizeOfElements;
        if (puVar9 <= puVar4) goto LAB_006e98c0;
        iVar5 = (*_PtFuncCompare)(puVar9,puVar4);
      } while (iVar5 == 0);
      if (puVar9 <= puVar4) goto LAB_006e98c0;
    }
    else {
LAB_006e98c0:
      do {
        puVar9 = puVar9 + -_SizeOfElements;
        if (puVar9 <= local_100) break;
        iVar5 = (*_PtFuncCompare)(puVar9,puVar4);
      } while (iVar5 == 0);
    }
    if ((int)puVar9 - (int)local_100 < (int)local_fc - (int)puVar8) goto LAB_006e991d;
    if (local_100 < puVar9) {
      auStack_f0[local_f4] = local_100;
      auStack_78[local_f4] = puVar9;
      local_f4 = local_f4 + 1;
    }
    local_100 = puVar8;
    if (local_fc <= puVar8) goto LAB_006e9776;
  }
  shortsort(local_100,local_fc,_SizeOfElements,_PtFuncCompare);
  goto LAB_006e9776;
LAB_006e991d:
  if (puVar8 < local_fc) {
    auStack_f0[local_f4] = puVar8;
    auStack_78[local_f4] = local_fc;
    local_f4 = local_f4 + 1;
  }
  local_fc = puVar9;
  if (puVar9 <= local_100) {
LAB_006e9776:
    local_f4 = local_f4 + -1;
    if (local_f4 < 0) {
      return;
    }
    local_100 = (undefined1 *)auStack_f0[local_f4];
    local_fc = (undefined1 *)auStack_78[local_f4];
  }
  goto LAB_006e9753;
}

