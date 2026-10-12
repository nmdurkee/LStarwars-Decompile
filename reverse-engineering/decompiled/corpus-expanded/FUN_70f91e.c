/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x70f91e; label: __ungetc_nolock
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __ungetc_nolock
   
   Library: Visual Studio 2005 Release */

int __cdecl __ungetc_nolock(int _Ch,FILE *_File)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  
  if ((_File->_flag & 0x40) == 0) {
    iVar2 = __fileno(_File);
    if ((iVar2 == -1) || (iVar2 = __fileno(_File), iVar2 == -2)) {
      puVar4 = &DAT_00829c00;
    }
    else {
      iVar2 = __fileno(_File);
      uVar3 = __fileno(_File);
      puVar4 = (undefined *)((uVar3 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar2 >> 5]);
    }
    if ((puVar4[0x24] & 0x7f) == 0) {
      iVar2 = __fileno(_File);
      if ((iVar2 == -1) || (iVar2 = __fileno(_File), iVar2 == -2)) {
        puVar4 = &DAT_00829c00;
      }
      else {
        iVar2 = __fileno(_File);
        uVar3 = __fileno(_File);
        puVar4 = (undefined *)((uVar3 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar2 >> 5]);
      }
      if ((puVar4[0x24] & 0x80) == 0) goto LAB_0070f9db;
    }
    puVar5 = (undefined4 *)FUN_006ead5f();
    *puVar5 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  else {
LAB_0070f9db:
    if (_Ch != -1) {
      uVar3 = _File->_flag;
      if (((uVar3 & 1) != 0) || (((char)uVar3 < '\0' && ((uVar3 & 2) == 0)))) {
        if (_File->_base == (char *)0x0) {
          __getbuf(_File);
        }
        if (_File->_ptr == _File->_base) {
          if (_File->_cnt != 0) {
            return -1;
          }
          _File->_ptr = _File->_ptr + 1;
        }
        _File->_ptr = _File->_ptr + -1;
        pcVar1 = _File->_ptr;
        if ((_File->_flag & 0x40) == 0) {
          *pcVar1 = (char)_Ch;
        }
        else if (*pcVar1 != (char)_Ch) {
          _File->_ptr = pcVar1 + 1;
          return -1;
        }
        _File->_cnt = _File->_cnt + 1;
        _File->_flag = _File->_flag & 0xffffffefU | 1;
        return _Ch & 0xff;
      }
    }
  }
  return -1;
}

