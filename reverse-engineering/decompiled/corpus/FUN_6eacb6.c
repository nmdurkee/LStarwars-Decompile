/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6eacb6; label: _ftell
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _ftell
   
   Library: Visual Studio 2005 Release */

long __cdecl _ftell(FILE *_File)

{
  undefined4 *puVar1;
  long lVar2;
  
  if (_File == (FILE *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    lVar2 = -1;
  }
  else {
    FUN_006e82ae(_File);
    lVar2 = __ftell_nolock(_File);
    FUN_006ead1a();
  }
  return lVar2;
}

