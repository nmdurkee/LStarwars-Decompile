/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e8ada; label: __fsopen
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 2005 Release */

FILE * __cdecl __fsopen(char *_Filename,char *_Mode,int _ShFlag)

{
  undefined4 *puVar1;
  int iVar2;
  FILE *pFVar3;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007ed098;
  uStack_c = 0x6e8ae6;
  if (((_Filename == (char *)0x0) || (_Mode == (char *)0x0)) || (*_Mode == '\0')) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  else {
    iVar2 = FUN_006f5c16();
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)FUN_006ead5f();
      *puVar1 = 0x18;
    }
    else {
      local_8 = (undefined *)0x0;
      if (*_Filename != '\0') {
        pFVar3 = (FILE *)FUN_006f5976(_Filename,_Mode,_ShFlag,iVar2);
        local_8 = (undefined *)0xfffffffe;
        FUN_006e8b94();
        return pFVar3;
      }
      puVar1 = (undefined4 *)FUN_006ead5f();
      *puVar1 = 0x16;
      __local_unwind4(&DAT_00829570,local_14,0xfffffffe);
    }
  }
  return (FILE *)0x0;
}

