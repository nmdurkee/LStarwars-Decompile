/* Ghidra analysis pseudocode, not original source.
 * ev_89d123adc6bf396b2f6b4ec3563e25957edd0c204114ec20eecbaddaafaf9a77
 * Entry: 0x6f2927; label: __stbuf
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __stbuf
   
   Library: Visual Studio 2005 Release */

int __cdecl __stbuf(FILE *_File)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = __fileno(_File);
  iVar3 = __isatty(iVar3);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = FUN_006e81d7();
  if (_File == (FILE *)(iVar3 + 0x20)) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_006e81d7();
    if (_File != (FILE *)(iVar3 + 0x40)) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_0297c198 = _DAT_0297c198 + 1;
  if ((_File->_flag & 0x10c) != 0) {
    return 0;
  }
  piVar1 = &DAT_0297cad4 + iVar3;
  if (*piVar1 == 0) {
    pvVar4 = __malloc_crt(0x1000);
    *piVar1 = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      _File->_base = (char *)&_File->_charbuf;
      _File->_ptr = (char *)&_File->_charbuf;
      _File->_bufsiz = 2;
      _File->_cnt = 2;
      goto LAB_006f29ab;
    }
  }
  pcVar2 = (char *)*piVar1;
  _File->_base = pcVar2;
  _File->_ptr = pcVar2;
  _File->_bufsiz = 0x1000;
  _File->_cnt = 0x1000;
LAB_006f29ab:
  _File->_flag = _File->_flag | 0x1102;
  return 1;
}

