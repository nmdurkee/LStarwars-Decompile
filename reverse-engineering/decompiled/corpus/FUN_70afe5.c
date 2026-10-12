/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70afe5; label: ____mb_cur_max_func
 */

/* Library Function - Single Match
    ____mb_cur_max_func
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl ____mb_cur_max_func(void)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  
  p_Var1 = __getptd();
  ptVar2 = p_Var1->ptlocinfo;
  if ((ptVar2 != (pthreadlocinfo)PTR_DAT_0082a678) && ((p_Var1->_ownlocale & DAT_0082a594) == 0)) {
    ptVar2 = ___updatetlocinfo();
  }
  return (int)ptVar2->locale_name[3];
}

