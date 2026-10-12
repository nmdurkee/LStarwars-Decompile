/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x703655; label: pDNameNode::length
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

/* Library Function - Single Match
    public: virtual int __thiscall pDNameNode::length(void)const 
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

int __thiscall pDNameNode::length(pDNameNode *this)

{
  int iVar1;
  
  if (*(DName **)(this + 8) != (DName *)0x0) {
    iVar1 = DName::length(*(DName **)(this + 8));
    return iVar1;
  }
  return 0;
}

