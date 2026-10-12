/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703501; label: Replicator::Replicator
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

