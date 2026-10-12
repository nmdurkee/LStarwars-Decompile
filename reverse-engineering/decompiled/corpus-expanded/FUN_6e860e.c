/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e860e; label: FUN_006e860e
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

