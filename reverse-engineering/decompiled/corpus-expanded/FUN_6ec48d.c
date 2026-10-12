/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ec48d; label: FID_conflict:__sscanf_s_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    __sscanf_l
    __sscanf_s_l
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict___sscanf_s_l(char *_Src,char *_Format,_locale_t _Locale,...)

{
  int iVar1;
  
  iVar1 = vscan_fn(&DAT_006fd715,_Format,_Locale,&stack0x00000010);
  return iVar1;
}

