/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x70faae; label: __fgetwc_nolock
 */

/* Library Function - Single Match
    __fgetwc_nolock
   
   Library: Visual Studio 2005 Release */

wint_t __cdecl __fgetwc_nolock(FILE *_File)

{
  int *piVar1;
  FILE *_File_00;
  wint_t wVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  size_t _SrcSizeInBytes;
  undefined4 local_8;
  
  _File_00 = _File;
  if ((_File->_flag & 0x40) == 0) {
    iVar3 = __fileno(_File);
    if ((iVar3 == -1) || (iVar3 = __fileno(_File_00), iVar3 == -2)) {
      puVar5 = &DAT_00829c00;
    }
    else {
      iVar3 = __fileno(_File_00);
      uVar4 = __fileno(_File_00);
      puVar5 = (undefined *)((uVar4 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar3 >> 5]);
    }
    if ((puVar5[0x24] & 0x7f) != 0) {
      piVar1 = &_File_00->_cnt;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        uVar4 = __filbuf(_File_00);
      }
      else {
        uVar4 = (uint)(byte)*_File_00->_ptr;
        _File_00->_ptr = _File_00->_ptr + 1;
      }
      if (uVar4 != 0xffffffff) {
        piVar1 = &_File_00->_cnt;
        *piVar1 = *piVar1 + -1;
        _File = (FILE *)CONCAT31(_File._1_3_,(char)uVar4);
        if (*piVar1 < 0) {
          uVar4 = __filbuf(_File_00);
        }
        else {
          uVar4 = (uint)(byte)*_File_00->_ptr;
          _File_00->_ptr = _File_00->_ptr + 1;
        }
        if (uVar4 != 0xffffffff) {
          _File._0_2_ = CONCAT11((char)uVar4,_File._0_1_);
          _File = (FILE *)(uint)(ushort)_File;
          goto LAB_0070fb4e;
        }
      }
      return 0xffff;
    }
    if ((_File_00->_flag & 0x40) == 0) {
      iVar3 = __fileno(_File_00);
      if ((iVar3 == -1) || (iVar3 = __fileno(_File_00), iVar3 == -2)) {
        puVar5 = &DAT_00829c00;
      }
      else {
        iVar3 = __fileno(_File_00);
        uVar4 = __fileno(_File_00);
        puVar5 = (undefined *)((uVar4 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar3 >> 5]);
      }
      if ((puVar5[4] & 0x80) != 0) {
        _SrcSizeInBytes = 1;
        piVar1 = &_File_00->_cnt;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          uVar4 = __filbuf(_File_00);
        }
        else {
          uVar4 = (uint)(byte)*_File_00->_ptr;
          _File_00->_ptr = _File_00->_ptr + 1;
        }
        if (uVar4 == 0xffffffff) {
          return 0xffff;
        }
        local_8 = CONCAT31(local_8._1_3_,(char)uVar4);
        iVar3 = _isleadbyte(uVar4 & 0xff);
        if (iVar3 != 0) {
          piVar1 = &_File_00->_cnt;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 0) {
            uVar4 = __filbuf(_File_00);
          }
          else {
            uVar4 = (uint)(byte)*_File_00->_ptr;
            _File_00->_ptr = _File_00->_ptr + 1;
          }
          if (uVar4 == 0xffffffff) {
            _ungetc((int)(char)local_8,_File_00);
            return 0xffff;
          }
          local_8._0_2_ = CONCAT11((char)uVar4,(char)local_8);
          _SrcSizeInBytes = 2;
        }
        iVar3 = _mbtowc((wchar_t *)&_File,(char *)&local_8,_SrcSizeInBytes);
        if (iVar3 == -1) {
          puVar6 = (undefined4 *)FUN_006ead5f();
          *puVar6 = 0x2a;
          return 0xffff;
        }
LAB_0070fb4e:
        return (ushort)_File;
      }
    }
  }
  piVar1 = &_File_00->_cnt;
  *piVar1 = *piVar1 + -2;
  if (*piVar1 < 0) {
    iVar3 = __filwbuf(_File_00);
    wVar2 = (wint_t)iVar3;
  }
  else {
    wVar2 = *(wint_t *)_File_00->_ptr;
    _File_00->_ptr = (char *)((int)_File_00->_ptr + 2);
  }
  return wVar2;
}

