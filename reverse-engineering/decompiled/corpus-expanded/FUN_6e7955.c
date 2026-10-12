/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e7955; label: FID_conflict:_wprintf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _printf
    _wprintf
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict__wprintf(char *_Format,...)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (_Format == (char *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    iVar3 = FUN_006e81d7();
    FUN_006e82ea(1,iVar3 + 0x20);
    iVar3 = FUN_006e81d7();
    iVar3 = __stbuf((FILE *)(iVar3 + 0x20));
    iVar4 = FUN_006e81d7(_Format,0,&stack0x00000008);
    iVar2 = FUN_006eef05(iVar4 + 0x20);
    iVar4 = FUN_006e81d7();
    __ftbuf(iVar3,(FILE *)(iVar4 + 0x20));
    FUN_006e79f1();
  }
  return iVar2;
}

