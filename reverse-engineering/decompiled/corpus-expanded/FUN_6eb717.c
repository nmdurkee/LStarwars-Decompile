/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eb717; label: _fprintf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fprintf
   
   Library: Visual Studio 2005 Release */

int __cdecl _fprintf(FILE *_File,char *_Format,...)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int local_20;
  
  local_20 = 0;
  if ((_File == (FILE *)0x0) || (_Format == (char *)0x0)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return -1;
  }
  FUN_006e82ae(_File);
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
      if ((puVar4[0x24] & 0x80) == 0) goto LAB_006eb81f;
    }
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    local_20 = -1;
  }
LAB_006eb81f:
  if (local_20 == 0) {
    iVar2 = __stbuf(_File);
    local_20 = FUN_006eef05(_File,_Format,0,&stack0x0000000c);
    __ftbuf(iVar2,_File);
  }
  FUN_006eb85c();
  return local_20;
}

