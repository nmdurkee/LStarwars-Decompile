/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e76c1; label: _realloc
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _realloc
   
   Library: Visual Studio 2005 Release */

void * __cdecl _realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  undefined4 uVar6;
  LPVOID pvVar7;
  int local_24;
  void *local_20;
  
  if (_Memory == (void *)0x0) {
    pvVar1 = _malloc(_NewSize);
    return pvVar1;
  }
  if (_NewSize == 0) {
    _free(_Memory);
    return (void *)0x0;
  }
  if (DAT_029a9b28 == 3) {
    do {
      local_20 = (void *)0x0;
      if (0xffffffe0 < _NewSize) goto LAB_006e789a;
      __lock(4);
      local_24 = thunk_FUN_006f19ca(_Memory);
      if (local_24 != 0) {
        if (_NewSize <= DAT_029a9b18) {
          iVar2 = ___sbh_resize_block(local_24,_Memory,_NewSize);
          if (iVar2 == 0) {
            local_20 = (void *)___sbh_alloc_block(_NewSize);
            if (local_20 != (void *)0x0) {
              uVar3 = *(int *)((int)_Memory + -4) - 1;
              if (_NewSize <= uVar3) {
                uVar3 = _NewSize;
              }
              _memcpy(local_20,_Memory,uVar3);
              local_24 = thunk_FUN_006f19ca(_Memory);
              ___sbh_free_block(local_24,_Memory);
            }
          }
          else {
            local_20 = _Memory;
          }
        }
        if (local_20 == (void *)0x0) {
          if (_NewSize == 0) {
            _NewSize = 1;
          }
          _NewSize = _NewSize + 0xf & 0xfffffff0;
          local_20 = HeapAlloc(DAT_0297c974,0,_NewSize);
          if (local_20 != (LPVOID)0x0) {
            uVar3 = *(int *)((int)_Memory + -4) - 1;
            if (_NewSize <= uVar3) {
              uVar3 = _NewSize;
            }
            _memcpy(local_20,_Memory,uVar3);
            ___sbh_free_block(local_24,_Memory);
          }
        }
      }
      FUN_006e7805();
      if (local_24 == 0) {
        if (_NewSize == 0) {
          _NewSize = 1;
        }
        _NewSize = _NewSize + 0xf & 0xfffffff0;
        local_20 = HeapReAlloc(DAT_0297c974,0,_Memory,_NewSize);
      }
      if (local_20 != (void *)0x0) {
        return local_20;
      }
      if (DAT_0297cad0 == 0) {
        puVar4 = (undefined4 *)FUN_006ead5f();
        if (local_24 != 0) {
          *puVar4 = 0xc;
          return (void *)0x0;
        }
        goto LAB_006e78c7;
      }
      iVar2 = __callnewh(_NewSize);
    } while (iVar2 != 0);
    puVar4 = (undefined4 *)FUN_006ead5f();
    if (local_24 != 0) goto LAB_006e78a6;
  }
  else {
    do {
      if (0xffffffe0 < _NewSize) goto LAB_006e789a;
      if (_NewSize == 0) {
        _NewSize = 1;
      }
      pvVar7 = HeapReAlloc(DAT_0297c974,0,_Memory,_NewSize);
      if (pvVar7 != (LPVOID)0x0) {
        return pvVar7;
      }
      if (DAT_0297cad0 == 0) {
        puVar4 = (undefined4 *)FUN_006ead5f();
LAB_006e78c7:
        DVar5 = GetLastError();
        uVar6 = FUN_006ead24(DVar5);
        *puVar4 = uVar6;
        return (void *)0x0;
      }
      iVar2 = __callnewh(_NewSize);
    } while (iVar2 != 0);
    puVar4 = (undefined4 *)FUN_006ead5f();
  }
  DVar5 = GetLastError();
  uVar6 = FUN_006ead24(DVar5);
  *puVar4 = uVar6;
  return (void *)0x0;
LAB_006e789a:
  __callnewh(_NewSize);
  puVar4 = (undefined4 *)FUN_006ead5f();
LAB_006e78a6:
  *puVar4 = 0xc;
  return (void *)0x0;
}

