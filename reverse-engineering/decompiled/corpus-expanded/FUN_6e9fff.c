/* Ghidra pseudocode, not original source.
 * ev_7917d444e56ee151ebe44b68491c815c9234e24f7023aa905c57d397c47edbbf
 * Entry: 0x6e9fff; label: std::bad_alloc::bad_alloc
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: __thiscall std::bad_alloc::bad_alloc(void)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this)

{
  exception::exception((exception *)this,&PTR_s_bad_allocation_008298dc,1);
  *(undefined ***)this = &PTR_FUN_0076a75c;
  return this;
}

