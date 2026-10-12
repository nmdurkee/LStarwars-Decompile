/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e8098; label: FID_conflict:_fputc
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _fputc
    _putc
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict__fputc(int _Ch,FILE *_File)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint local_20;
  
  local_20 = 0;
  if (_File == (FILE *)0x0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return -1;
  }
  FUN_006e82ae(_File);
  if ((_File->_flag & 0x40) == 0) {
    iVar3 = __fileno(_File);
    if ((iVar3 == -1) || (iVar3 = __fileno(_File), iVar3 == -2)) {
      puVar5 = &DAT_00829c00;
    }
    else {
      iVar3 = __fileno(_File);
      uVar4 = __fileno(_File);
      puVar5 = (undefined *)((uVar4 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar3 >> 5]);
    }
    if ((puVar5[0x24] & 0x7f) == 0) {
      iVar3 = __fileno(_File);
      if ((iVar3 == -1) || (iVar3 = __fileno(_File), iVar3 == -2)) {
        puVar5 = &DAT_00829c00;
      }
      else {
        iVar3 = __fileno(_File);
        uVar4 = __fileno(_File);
        puVar5 = (undefined *)((uVar4 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar3 >> 5]);
      }
      if ((puVar5[0x24] & 0x80) == 0) goto LAB_006e8191;
    }
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    local_20 = 0xffffffff;
  }
LAB_006e8191:
  if (local_20 == 0) {
    piVar1 = &_File->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      local_20 = __flsbuf(_Ch,_File);
    }
    else {
      *_File->_ptr = (char)_Ch;
      local_20 = _Ch & 0xff;
      _File->_ptr = _File->_ptr + 1;
    }
  }
  FUN_006e81cf();
  return local_20;
}

