/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x7036c3; label: UnDecorator::UnDecorator
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: __thiscall UnDecorator::UnDecorator(char *,char const *,int,char *
   (__cdecl*)(long),unsigned long)
   
   Library: Visual Studio 2005 Release */

UnDecorator * __thiscall
UnDecorator::UnDecorator
          (UnDecorator *this,char *param_1,char *param_2,int param_3,_func_char_ptr_long *param_4,
          ulong param_5)

{
  Replicator::Replicator((Replicator *)this);
  Replicator::Replicator((Replicator *)(this + 0x3c));
  DAT_0297cb7c = param_2;
  DAT_0297cb78 = param_2;
  if (param_1 == (char *)0x0) {
    DAT_0297cb80 = (char *)0x0;
    DAT_0297cb84 = 0;
  }
  else {
    DAT_0297cb84 = param_3 + -1;
    DAT_0297cb80 = param_1;
  }
  DAT_0297cb88 = param_5;
  DAT_0297cb70 = (Replicator *)(this + 0x3c);
  DAT_0297cb8c = param_4;
  DAT_0297cb6c = this;
  DAT_0297cb90 = 0;
  return this;
}

