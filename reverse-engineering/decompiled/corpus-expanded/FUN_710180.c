/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x710180; label: __wcstombs_s_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __wcstombs_s_l
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl
__wcstombs_s_l(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,wchar_t *_Src,
              size_t _MaxCountInBytes,_locale_t _Locale)

{
  size_t sVar1;
  int iVar2;
  errno_t *peVar3;
  uint uVar4;
  errno_t eVar5;
  errno_t local_8;
  
  local_8 = 0;
  if (_Dst == (char *)0x0) {
    if (_DstSizeInBytes != 0) goto LAB_007101da;
  }
  else if (_DstSizeInBytes == 0) {
LAB_007101da:
    peVar3 = (errno_t *)FUN_006ead5f();
    eVar5 = 0x16;
    goto LAB_007101e1;
  }
  if (_Dst != (char *)0x0) {
    *_Dst = '\0';
  }
  if (_PtNumOfCharConverted != (size_t *)0x0) {
    *_PtNumOfCharConverted = 0;
  }
  sVar1 = _MaxCountInBytes;
  if (_DstSizeInBytes < _MaxCountInBytes) {
    sVar1 = _DstSizeInBytes;
  }
  iVar2 = __wcstombs_l_helper(_Dst,_Src,sVar1,_Locale);
  if (iVar2 == -1) {
    if (_Dst != (char *)0x0) {
      *_Dst = '\0';
    }
    peVar3 = (errno_t *)FUN_006ead5f();
    return *peVar3;
  }
  uVar4 = iVar2 + 1;
  if (_Dst != (char *)0x0) {
    if (_DstSizeInBytes < uVar4) {
      if ((_MaxCountInBytes != 0xffffffff) && (*_Dst = '\0', _DstSizeInBytes <= uVar4)) {
        peVar3 = (errno_t *)FUN_006ead5f();
        eVar5 = 0x22;
LAB_007101e1:
        *peVar3 = eVar5;
        FUN_006e9fc2(0,0,0,0,0);
        return eVar5;
      }
      local_8 = 0x50;
      uVar4 = _DstSizeInBytes;
    }
    _Dst[uVar4 - 1] = '\0';
  }
  if (_PtNumOfCharConverted == (size_t *)0x0) {
    return local_8;
  }
  *_PtNumOfCharConverted = uVar4;
  return local_8;
}

