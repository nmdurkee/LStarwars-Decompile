/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x712bce; label: __chsize_nolock
 */

/* Library Function - Single Match
    __chsize_nolock
   
   Library: Visual Studio 2005 Release */

int __cdecl __chsize_nolock(int _FileHandle,longlong _Size)

{
  int iVar1;
  HANDLE pvVar2;
  LPVOID _Buf;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  BOOL BVar7;
  DWORD *pDVar8;
  uint uVar9;
  int unaff_EDI;
  int iVar10;
  bool bVar11;
  bool bVar12;
  ulonglong uVar13;
  longlong lVar14;
  uint in_stack_00000008;
  DWORD DVar15;
  SIZE_T dwBytes;
  uint local_14;
  uint local_10;
  
  local_14 = 0;
  local_10 = 0;
  uVar13 = __lseeki64_nolock(_FileHandle,0x100000000,unaff_EDI);
  if (uVar13 == 0xffffffffffffffff) goto LAB_00712c54;
  lVar14 = __lseeki64_nolock(_FileHandle,0x200000000,unaff_EDI);
  iVar5 = (int)((ulonglong)lVar14 >> 0x20);
  if (lVar14 == -1) goto LAB_00712c54;
  uVar9 = in_stack_00000008 - (uint)lVar14;
  uVar6 = (uint)(in_stack_00000008 < (uint)lVar14);
  iVar1 = (int)_Size - iVar5;
  iVar10 = iVar1 - uVar6;
  if ((iVar10 < 0) ||
     ((iVar10 == 0 || SBORROW4((int)_Size,iVar5) != SBORROW4(iVar1,uVar6) && (uVar9 == 0)))) {
    if ((iVar10 < 1) && (iVar10 < 0)) {
      lVar14 = __lseeki64_nolock(_FileHandle,_Size & 0xffffffff,unaff_EDI);
      if (lVar14 == -1) goto LAB_00712c54;
      pvVar2 = (HANDLE)__get_osfhandle(_FileHandle);
      BVar7 = SetEndOfFile(pvVar2);
      local_14 = (BVar7 != 0) - 1;
      local_10 = (int)local_14 >> 0x1f;
      if ((local_14 & local_10) == 0xffffffff) {
        puVar3 = (undefined4 *)FUN_006ead5f();
        *puVar3 = 0xd;
        pDVar8 = (DWORD *)FUN_006ead72();
        DVar15 = GetLastError();
        *pDVar8 = DVar15;
        goto LAB_00712d52;
      }
    }
  }
  else {
    dwBytes = 0x1000;
    DVar15 = 8;
    pvVar2 = GetProcessHeap();
    _Buf = HeapAlloc(pvVar2,DVar15,dwBytes);
    if (_Buf == (LPVOID)0x0) {
      puVar3 = (undefined4 *)FUN_006ead5f();
      *puVar3 = 0xc;
      goto LAB_00712c54;
    }
    iVar5 = __setmode_nolock(_FileHandle,0x8000);
    while( true ) {
      uVar6 = uVar9;
      if ((-1 < iVar10) && ((0 < iVar10 || (0xfff < uVar9)))) {
        uVar6 = 0x1000;
      }
      uVar6 = __write_nolock(_FileHandle,_Buf,uVar6);
      if (uVar6 == 0xffffffff) break;
      bVar11 = uVar9 < uVar6;
      uVar9 = uVar9 - uVar6;
      bVar12 = SBORROW4(iVar10,(int)uVar6 >> 0x1f);
      iVar1 = iVar10 - ((int)uVar6 >> 0x1f);
      iVar10 = iVar1 - (uint)bVar11;
      if ((iVar10 < 0) || ((iVar10 == 0 || bVar12 != SBORROW4(iVar1,(uint)bVar11) && (uVar9 == 0))))
      goto LAB_00712ca6;
    }
    piVar4 = (int *)FUN_006ead72();
    if (*piVar4 == 5) {
      puVar3 = (undefined4 *)FUN_006ead5f();
      *puVar3 = 0xd;
    }
    local_14 = 0xffffffff;
    local_10 = 0xffffffff;
LAB_00712ca6:
    __setmode_nolock(_FileHandle,iVar5);
    DVar15 = 0;
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,DVar15,_Buf);
LAB_00712d52:
    if ((local_14 & local_10) == 0xffffffff) goto LAB_00712c54;
  }
  lVar14 = __lseeki64_nolock(_FileHandle,uVar13 >> 0x20,unaff_EDI);
  if (lVar14 != -1) {
    return 0;
  }
LAB_00712c54:
  piVar4 = (int *)FUN_006ead5f();
  return *piVar4;
}

