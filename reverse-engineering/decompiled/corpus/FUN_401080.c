/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x401080; label: `vector_constructor_iterator'
 */

/* Library Function - Single Match
    void __stdcall `vector constructor iterator'(void *,unsigned int,int,void * (__thiscall*)(void
   *))
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void _vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_ptr_void_ptr *param_4)

{
  void *unaff_ESI;
  
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_ESI);
  }
  return;
}

