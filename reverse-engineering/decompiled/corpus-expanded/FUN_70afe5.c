/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70afe5; label: ____mb_cur_max_func
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

