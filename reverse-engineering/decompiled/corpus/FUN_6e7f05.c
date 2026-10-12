/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e7f05; label: FID_conflict:_vfprintf
 */

/* Library Function - Multiple Matches With Different Base Names
    __vfprintf_p
    _vfprintf
    _vfprintf_s
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict__vfprintf(FILE *_File,char *_Format,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = vfprintf_helper(FUN_006eef05,_File,_Format,0,_ArgList);
  return iVar1;
}

