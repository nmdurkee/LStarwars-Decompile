/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70c101; label: __Strftime
 */

/* Library Function - Single Match
    __Strftime
   
   Library: Visual Studio 2005 Release */

size_t __cdecl __Strftime(char *param_1,size_t _Maxsize,char *param_3,tm *param_4,void *param_5)

{
  size_t sVar1;
  
  sVar1 = __Strftime_l(param_1,_Maxsize,param_3,param_4,param_5,0);
  return sVar1;
}

