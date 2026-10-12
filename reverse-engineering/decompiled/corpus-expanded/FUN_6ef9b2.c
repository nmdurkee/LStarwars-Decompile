/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6ef9b2; label: __vsprintf_s_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __vsprintf_s_l
   
   Library: Visual Studio 2005 Release */

int __cdecl
__vsprintf_s_l(char *_DstBuf,size_t _DstSize,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (_Format == (char *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  else {
    if ((_DstBuf == (char *)0x0) || (_DstSize == 0)) {
      puVar1 = (undefined4 *)FUN_006ead5f();
      *puVar1 = 0x16;
    }
    else {
      iVar2 = __vsnprintf_helper(&DAT_006f3d42,_DstBuf,_DstSize,_Format,_Locale,_ArgList);
      if (iVar2 < 0) {
        *_DstBuf = '\0';
      }
      if (iVar2 != -2) {
        return iVar2;
      }
      puVar1 = (undefined4 *)FUN_006ead5f();
      *puVar1 = 0x22;
    }
    FUN_006e9fc2(0,0,0,0,0);
  }
  return -1;
}

