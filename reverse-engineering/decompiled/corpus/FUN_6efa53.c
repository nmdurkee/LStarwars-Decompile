/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6efa53; label: __vsnprintf_s_l
 */

/* Library Function - Single Match
    __vsnprintf_s_l
   
   Library: Visual Studio 2005 Release */

int __cdecl
__vsnprintf_s_l(char *_DstBuf,size_t _DstSize,size_t _MaxCount,char *_Format,_locale_t _Locale,
               va_list _ArgList)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  if (_Format == (char *)0x0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return -1;
  }
  if (_MaxCount == 0) {
    if (_DstBuf == (char *)0x0) {
      if (_DstSize == 0) {
        return 0;
      }
    }
    else {
LAB_006efa9d:
      if (_DstSize != 0) {
        puVar2 = (undefined4 *)FUN_006ead5f();
        if (_MaxCount < _DstSize) {
          uVar1 = *puVar2;
          iVar3 = __vsnprintf_helper(&DAT_006f3d42,_DstBuf,_MaxCount + 1,_Format,_Locale,_ArgList);
          if (iVar3 == -2) {
            piVar4 = (int *)FUN_006ead5f();
            if (*piVar4 != 0x22) {
              return -1;
            }
            puVar2 = (undefined4 *)FUN_006ead5f();
            *puVar2 = uVar1;
            return -1;
          }
LAB_006efb2d:
          if (-1 < iVar3) {
            return iVar3;
          }
        }
        else {
          uVar1 = *puVar2;
          iVar3 = __vsnprintf_helper(&DAT_006f3d42,_DstBuf,_DstSize,_Format,_Locale,_ArgList);
          _DstBuf[_DstSize - 1] = '\0';
          if (iVar3 != -2) goto LAB_006efb2d;
          if (_MaxCount == 0xffffffff) {
            piVar4 = (int *)FUN_006ead5f();
            if (*piVar4 != 0x22) {
              return -1;
            }
            puVar2 = (undefined4 *)FUN_006ead5f();
            *puVar2 = uVar1;
            return -1;
          }
        }
        *_DstBuf = '\0';
        if (iVar3 != -2) {
          return -1;
        }
        puVar2 = (undefined4 *)FUN_006ead5f();
        *puVar2 = 0x22;
        goto LAB_006efb43;
      }
    }
  }
  else if (_DstBuf != (char *)0x0) goto LAB_006efa9d;
  puVar2 = (undefined4 *)FUN_006ead5f();
  *puVar2 = 0x16;
LAB_006efb43:
  FUN_006e9fc2(0,0,0,0,0);
  return -1;
}

