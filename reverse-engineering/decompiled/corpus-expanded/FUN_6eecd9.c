/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6eecd9; label: __flsbuf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __flsbuf
   
   Library: Visual Studio 2005 Release */

int __cdecl __flsbuf(int _Ch,FILE *_File)

{
  char *_Buf;
  char *pcVar1;
  FILE *_File_00;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  int unaff_EDI;
  uint uVar5;
  longlong lVar6;
  uint local_8;
  
  _File_00 = _File;
  _File = (FILE *)__fileno(_File);
  uVar5 = _File_00->_flag;
  if ((uVar5 & 0x82) == 0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 9;
LAB_006eecfd:
    _File_00->_flag = _File_00->_flag | 0x20;
    return -1;
  }
  if ((uVar5 & 0x40) != 0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x22;
    goto LAB_006eecfd;
  }
  if ((uVar5 & 1) != 0) {
    _File_00->_cnt = 0;
    if ((uVar5 & 0x10) == 0) {
      _File_00->_flag = uVar5 | 0x20;
      return -1;
    }
    _File_00->_ptr = _File_00->_base;
    _File_00->_flag = uVar5 & 0xfffffffe;
  }
  uVar5 = _File_00->_flag;
  _File_00->_flag = uVar5 & 0xffffffef | 2;
  _File_00->_cnt = 0;
  local_8 = 0;
  if (((uVar5 & 0x10c) == 0) &&
     (((iVar3 = FUN_006e81d7(), _File_00 != (FILE *)(iVar3 + 0x20) &&
       (iVar3 = FUN_006e81d7(), _File_00 != (FILE *)(iVar3 + 0x40))) ||
      (iVar3 = __isatty((int)_File), iVar3 == 0)))) {
    __getbuf(_File_00);
  }
  if ((_File_00->_flag & 0x108) == 0) {
    uVar5 = 1;
    local_8 = __write((int)_File,&_Ch,1);
  }
  else {
    _Buf = _File_00->_base;
    pcVar1 = _File_00->_ptr;
    _File_00->_ptr = _Buf + 1;
    uVar5 = (int)pcVar1 - (int)_Buf;
    _File_00->_cnt = _File_00->_bufsiz + -1;
    if ((int)uVar5 < 1) {
      if ((_File == (FILE *)0xffffffff) || (_File == (FILE *)0xfffffffe)) {
        puVar4 = &DAT_00829c00;
      }
      else {
        puVar4 = (undefined *)(((uint)_File & 0x1f) * 0x38 + (&DAT_029a9b40)[(int)_File >> 5]);
      }
      if (((puVar4[4] & 0x20) != 0) &&
         (lVar6 = __lseeki64((int)_File,0x200000000,unaff_EDI), lVar6 == -1)) goto LAB_006eee23;
    }
    else {
      local_8 = __write((int)_File,_Buf,uVar5);
    }
    *_File_00->_base = (char)_Ch;
  }
  if (local_8 == uVar5) {
    return _Ch & 0xff;
  }
LAB_006eee23:
  _File_00->_flag = _File_00->_flag | 0x20;
  return -1;
}

