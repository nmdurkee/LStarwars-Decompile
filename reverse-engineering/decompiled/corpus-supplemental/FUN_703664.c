/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x703664; label: pDNameNode::getLastChar
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

/* Library Function - Single Match
    public: virtual char __thiscall pDNameNode::getLastChar(void)const 
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

char __thiscall pDNameNode::getLastChar(pDNameNode *this)

{
  char cVar1;
  
  if (*(DName **)(this + 8) != (DName *)0x0) {
    cVar1 = DName::getLastChar(*(DName **)(this + 8));
    return cVar1;
  }
  return '\0';
}

