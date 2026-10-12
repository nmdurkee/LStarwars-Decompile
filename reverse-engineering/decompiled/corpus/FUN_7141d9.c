/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x7141d9; label: __filwbuf
 */

/* Library Function - Single Match
    __filwbuf
   
   Library: Visual Studio 2005 Release */

int __cdecl __filwbuf(FILE *_File)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  char *pcVar7;
  
  if (_File == (FILE *)0x0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  else {
    uVar5 = _File->_flag;
    if (((uVar5 & 0x83) != 0) && ((uVar5 & 0x40) == 0)) {
      if ((uVar5 & 2) == 0) {
        _File->_flag = uVar5 | 1;
        if ((uVar5 & 0x10c) == 0) {
          __getbuf(_File);
        }
        else {
          _File->_ptr = _File->_base;
        }
        iVar4 = _File->_bufsiz;
        pcVar7 = _File->_base;
        iVar3 = __fileno(_File);
        iVar4 = FUN_006f572b(iVar3,pcVar7,iVar4);
        _File->_cnt = iVar4;
        if (((iVar4 != 0) && (iVar4 != 1)) && (iVar4 != -1)) {
          if ((_File->_flag & 0x82) == 0) {
            iVar4 = __fileno(_File);
            if ((iVar4 == -1) || (iVar4 = __fileno(_File), iVar4 == -2)) {
              puVar6 = &DAT_00829c00;
            }
            else {
              iVar4 = __fileno(_File);
              uVar5 = __fileno(_File);
              puVar6 = (undefined *)((uVar5 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar4 >> 5]);
            }
            if ((puVar6[4] & 0x82) == 0x82) {
              _File->_flag = _File->_flag | 0x2000;
            }
          }
          if (((_File->_bufsiz == 0x200) && ((_File->_flag & 8U) != 0)) &&
             ((_File->_flag & 0x400U) == 0)) {
            _File->_bufsiz = 0x1000;
          }
          _File->_cnt = _File->_cnt + -2;
          uVar1 = *(ushort *)_File->_ptr;
          _File->_ptr = (char *)((int)_File->_ptr + 2);
          return (uint)uVar1;
        }
        _File->_flag = _File->_flag | (-(uint)(iVar4 != 0) & 0x10) + 0x10;
        _File->_cnt = 0;
      }
      else {
        _File->_flag = uVar5 | 0x20;
      }
    }
  }
  return 0xffff;
}

