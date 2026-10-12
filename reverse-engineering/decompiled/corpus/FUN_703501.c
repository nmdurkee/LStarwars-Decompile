/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703501; label: Replicator::Replicator
 */

/* Library Function - Single Match
    public: __thiscall Replicator::Replicator(void)
   
   Library: Visual Studio 2005 Release */

Replicator * __thiscall Replicator::Replicator(Replicator *this)

{
  DName::DName((DName *)(this + 0x2c),3);
  DName::DName((DName *)(this + 0x34),1);
  *(undefined4 *)this = 0xffffffff;
  return this;
}

