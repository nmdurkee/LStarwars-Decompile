/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e860e; label: FUN_006e860e
 */

int FUN_006e860e(FILE *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -1;
  if (param_1 == (FILE *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar3 = -1;
  }
  else {
    if ((param_1->_flag & 0x83) != 0) {
      iVar3 = __flush(param_1);
      __freebuf(param_1);
      iVar2 = __fileno(param_1);
      iVar2 = __close(iVar2);
      if (iVar2 < 0) {
        iVar3 = -1;
      }
      else if (param_1->_tmpfname != (char *)0x0) {
        _free(param_1->_tmpfname);
        param_1->_tmpfname = (char *)0x0;
      }
    }
    param_1->_flag = 0;
  }
  return iVar3;
}

